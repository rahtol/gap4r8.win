#include        <stdio.h>
#include        <assert.h>
#include "bec_debug.h"
#include        "src/system.h"          /* Ints, UInts                     */
#include        "src/gasman.h"          /* garbage collector               */
#include        "src/objects.h"         /* objects                         */
#include "src/bool.h"
#include "src/gap.h"
#include "src/string.h"
#include "src/plist.h"
#include "src/calls.h"
#include "src/vars.h"
#include "src/code.h"

Obj Shell(Obj context,
	UInt canReturnVoid,
	UInt canReturnObj,
	UInt lastDepth,
	UInt setTime,
	Char *prompt,
	Obj preCommandHook,
	UInt catchQUIT,
	Char *inFile,
	Char *outFile);

extern Obj FilenameCache;

#define MAXBP 16
int singlestepmode = 0;
struct breakppointdata {
	UInt filenameId;
	Obj lineno;
} breakpointtable [MAXBP+2];

void initializebreakpointttable()
{
	/* initialize the breakpoint table */
	for (int i = 0; i <= MAXBP; i++)
	{
		breakpointtable[i].filenameId = 0;
		breakpointtable[i].lineno = INTOBJ_INT(0);
	};
};

int breakpointadd(UInt filenameId, Obj lineno)
{
	int i = 1;
	while (breakpointtable[i].filenameId != 0)
	{
		i++;
		if (i > MAXBP) return -1;
	};

	breakpointtable[i].filenameId = filenameId;
	breakpointtable[i].lineno = lineno;

	return i;
};

int breakpointfound(UInt filenameId, Int lineno)
{
	if (singlestepmode != 0)
	{
		// break due to activated singlestepmode
		return 0;
	}

	int i = 1;
	while (breakpointtable[i].filenameId != 0)
	{
		if ((breakpointtable[i].filenameId == filenameId) && 
			(((Int)breakpointtable[i].lineno)==((Int)INTOBJ_INT(lineno))))
		{
			// break at breakpoint #i
			return i;
		};
		i++;
		if (i > MAXBP) break;
	};
	return -1;
}

Char conv(Char c)
{
	if (c == '\\') return '/';
	return c;
};

int filennamematch(Char *fullfn, Char *fn)
{
	int len0 = strlen (fullfn);
	int len1 = strlen(fn);

	while (len1 > 0)
	{
		if (len0 <= 0) return -1;
		if (conv(fullfn[len0-1]) != conv(fn[len1-1])) return 0;
		len0--;
		len1--;
	}

	return (len0 == 0) || (conv(fullfn[len0-1]) == '/') || (fullfn[len0-1] == ':');
};

Obj FuncSetBP (Obj self, Obj fname, Obj lineno)
{
	Char *cfname = CSTR_STRING(fname);

	if (strcmp(cfname, "STEP") == 0)
	{
		singlestepmode = 1;
		return INTOBJ_INT(0);
	};

	UInt len = LEN_PLIST(FilenameCache);
	for (UInt i = 1; i <= len; i++) {
		Obj fn = ELM_PLIST(FilenameCache, i);
		Char *cfn = CSTR_STRING(fn);
		if (filennamematch(cfn, cfname))
		{
			// add (i, lineno) to breakpoint table
			int bp = breakpointadd(i, lineno);
			return (bp > 0 ? INTOBJ_INT(bp) : Fail);
		};
	};

	// failure, most likely since fname does not exist in FilenameCache
	return Fail;
};

void mkdbgprompt(char *s, int smax, UInt filenameId, Int lineno)
{
	Obj fn = ELM_PLIST(FilenameCache, filenameId);
	Char *cfn0 = CSTR_STRING(fn);
	size_t len = strlen(cfn0);
	size_t i = len;
	while (i > 0) {
		if (conv(cfn0[i-1]) == '/') break;
		if (conv(cfn0[i-1]) == ':') break;
		i--;
		if (len - i >= smax - 10) break;
	};
	sprintf_s(s, smax, "%s#%04d#dbg>", cfn0 + i, lineno);
};

void chkdbg(Stat stat)
{
	static UInt last_filenameId = 0;
	static Int last_lineno = 0;

	UInt filenameId = FILENAMEID_STAT(stat);
	Int lineno = LINE_STAT(stat);

	int id = -1;

	if (((last_filenameId != filenameId) || (last_lineno != lineno)) && 
		 ((id = breakpointfound(filenameId, lineno)) >= 0))
	{
		Char dbgprompt[32];
		mkdbgprompt(dbgprompt, 32, filenameId, lineno);
		Shell (CurrLVars, 1, 0, 1, 0, dbgprompt, NULL, 0, "*errin*", "*errout*");
	}

	last_filenameId = filenameId;
	last_lineno = lineno;
}

Obj FuncClearBP(Obj self)
{
	initializebreakpointttable();
	return INTOBJ_INT(0);
};

Obj FuncListBP(Obj self)
{
	int i = 0;
	while (breakpointtable[++i].filenameId != 0)
	{
		Obj fn = ELM_PLIST(FilenameCache, breakpointtable[i].filenameId);
		Char *cfn = CSTR_STRING(fn);
		UInt lineno = INT_INTOBJ(breakpointtable[i].lineno);
		printf("%02d: \"%s\", line %d\n", i, cfn, lineno);
		if (i == MAXBP) break;
	};
	return INTOBJ_INT(i-1);
};

/****************************************************************************
**
*V  GVarFuncs . . . . . . . . . . . . . . . . . . list of functions to export
*/
static StructGVarFunc GVarFuncs[] = {

	{ "SetBP", 2, "string, int", FuncSetBP, "src/bec_debug.c:FuncSetBP" },
	{ "ClearBP", 0, "", FuncClearBP, "src/bec_debug.c:FuncClearBP" },
	{ "ListBP", 0, "", FuncListBP, "src/bec_debug.c:FuncListBP" },
	{ 0 }
};

/****************************************************************************
**

*F  InitKernel( <module> )  . . . . . . . . initialise kernel data structures
*/
static Int InitKernel(
	StructInitInfo *    module)
{

	/* init filters and functions                                          */
//	InitHdlrFiltsFromTable(GVarFilts);
	InitHdlrFuncsFromTable(GVarFuncs);

	/* return success                                                      */
	return 0;
}


/****************************************************************************
**
*F  InitLibrary( <module> ) . . . . . . .  initialise library data structures
*/
static Int InitLibrary(
	StructInitInfo *    module)
{
	/* init filters and functions                                          */
//	InitGVarFiltsFromTable(GVarFilts);
	InitGVarFuncsFromTable(GVarFuncs);

	initializebreakpointttable();

	/* return success */
	return 0;
}


/****************************************************************************
**
*F  InitInfoPermutat()  . . . . . . . . . . . . . . . table of init functions
*/
static StructInitInfo module = {
	MODULE_BUILTIN,                     /* type                           */
	"debug",                            /* name                           */
	0,                                  /* revision entry of c file       */
	0,                                  /* revision entry of h file       */
	0,                                  /* version                        */
	0,                                  /* crc                            */
	InitKernel,                         /* initKernel                     */
	InitLibrary,                        /* initLibrary                    */
	0,                                  /* checkInit                      */
	0,                                  /* preSave                        */
	0,                                  /* postSave                       */
	0                                   /* postRestore                    */
};

StructInitInfo * InitInfoDebug(void)
{
	return &module;
}


/****************************************************************************
**

*E  bec_debug.c  . . . . . . . . . . . . . . . . . . . . . . . . . ends here
*/
