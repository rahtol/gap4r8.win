#include <stdio.h>
#include <malloc.h>

#define _REENT_EMERGENCY_SIZE 25

struct _reent
{
	int _errno;			/* local copy of errno */

						/* FILE is a big struct and may change over time.  To try to achieve binary
						compatibility with future versions, put stdin,stdout,stderr here.
						These are pointers into member __sf defined below.  */
	FILE *_stdin, *_stdout, *_stderr;

	int  _inc;			/* used by tmpnam */
	char _emergency[_REENT_EMERGENCY_SIZE];

	int _current_category;	/* used by setlocale */
	char *_current_locale;

	int __sdidinit;		/* 1 means stdio has been init'd */

	int buffer[64];

} _new;

void init_reent(struct _reent *r)
{
	r->_stdin = stdin;
	r->_stdout = stdout;
	r->_stderr = stderr;
}

struct _reent *__getreent()
{
	static struct _reent *bec_reent = NULL;
	if (bec_reent == NULL) {
		bec_reent = (struct _reent *) malloc(sizeof(struct _reent));
		init_reent(bec_reent);
	}
	return bec_reent;
};

