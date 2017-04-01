#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

//char **environ;

/*
static char __ctype_data__ [257] ={ 0,
	32,  32,  32,  32,  32,  32,  32,  32,  32,  40,  40,  40,  40,  40,  32,  32,
	32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,
	136,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,
	4,   4,   4,   4,   4,   4,   4,   4,   4,   4,  16,  16,  16,  16,  16,  16,
	16,  65,  65,  65,  65,  65,  65,   1,   1,   1,   1,   1,   1,   1,   1,   1,
	1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,  16,  16,  16,  16,  16,
	16,  66,  66,  66,  66,  66,  66,   2,   2,   2,   2,   2,   2,   2,   2,   2,
	2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,  16,  16,  16,  16,  32,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 };

char *__ctype_ptr__ = &(__ctype_data__[0]);
*/

typedef int pid_t;
typedef unsigned long sigset_t;


struct _reent
{
	long dummy[64];
};

struct stat
{
	long dummy[64];
};

struct winsize
{
	long dummy[64];
};

typedef union
{
	int *__int_ptr;
	union wait *__union_wait_ptr;
} __wait_status_ptr_t;



extern int becmain(int, char**, char**);

int main2 (
          int                 argc,
          char *              argv [],
          char *              environ [] )
{
	return 0;

//	becmain(argc, argv, environ);
}

void __assert_func(const char *file, int line, const char *s, const char *condition)
{
	printf("file=%s, line=%d, s=%s, condition=%s", file, line, s, condition);
};

int *__errno(void)
{
	return _errno();
};

char *dlerror(void)
{
	_ASSERTE(0);
	return NULL;
};

void *dlopen (const char *x, int xx)
{
	_ASSERTE(0);
	return NULL;
};

int dlclose (void *x)
{
	_ASSERTE(0);
	return 0;
};

void *dlsym (void *x, const char *xx)
{
	_ASSERTE(0);
	return NULL;
};

double exp10 (double x)
{
	_ASSERTE(0);
	return x;
};

//FILE* fdopen(int fd, const char * mode)
//{
//	return _fdopen(fd, mode);
//}

int fcntl (int fd, int cmd, ...)
{
	_ASSERTE(0);
	return 0; // ???
}

int	fileno (FILE *f)
{
	return _fileno(f);
};

pid_t fork (void)
{
	_ASSERTE(0);
	return 0;
};

int getrusage (int __who, struct rusage *__rusage)
{
	_ASSERTE(0);
	return 0;
};

int gettimeofday (struct timeval *__restrict __p, void *__restrict __tz)
{
	_ASSERTE(0);
	return 0;
};

int __cdecl ioctl (int __fd, int __cmd, ...)
{
//	_ASSERTE(0); called during intialisation context getwindow
	return 0;
};

int kill (pid_t x, int xx)
{
	_ASSERTE(0);
	return 0;
};

int lstat(const char *__restrict __path, struct stat *__restrict __buf)
{
	_ASSERTE(0);
	return 0;
};

int madvise (void *__addr, size_t __len, int __advice)
{
	_ASSERTE(0);
	return 0;
};

char *mkdtemp (char *x)
{
	_ASSERTE(0);
	return NULL;
};

int mkstemp (char *x)
{
	_ASSERTE(0);
	return 0;
};

void *mmap(void *__addr, size_t __len, int __prot, int __flags, int __fd, off_t __off)
{
	_ASSERTE(0);
	return NULL;
};

int munmap(void *__addr, size_t __len)
{
	_ASSERTE(0);
	return 0;
};

int openpty (int *x, int *xx, char *xxx, const struct termios *xxxx, const struct winsize *xxxxx)
{
	_ASSERTE(0);
	return 0;
};

int	pclose(FILE *x)
{
	_ASSERTE(0);
	return 0;
};

FILE *popen (const char *x, const char *xx)
{
	_ASSERTE(0);
	return NULL;
};

char *realpath(const char *__restrict path, char *__restrict resolved_path)
{
	_ASSERTE(0);
	return NULL;
};

void *sbrk (ptrdiff_t __incr)
{
	static char *pool = NULL;
	static char *poolptr = NULL;
	static long int MAX_POOL = 1024 * 1024 * 1024; // 1GB max poolsize

	if (pool == NULL) {
		pool = (char *)malloc(MAX_POOL);
		poolptr = pool;
	};

	_ASSERTE((poolptr - pool) + __incr >= 0);
	_ASSERTE((poolptr - pool) + __incr <= MAX_POOL);

	{
		char *tmpptr = poolptr;
		poolptr = poolptr + __incr;
		return (void *)tmpptr;
	}
};

int select (int x, ...)
{
	_ASSERTE(0);
	return 0;
}

int setpgid(pid_t __pid, pid_t __pgid)
{
	_ASSERTE(0);
	return 0;
};

int sigaction(int x, const struct sigaction *xx, struct sigaction *xxx)
{
	_ASSERTE(0);
	return 0;
};

int siginterrupt (int x, int xx)
{
	// changes restart behavior of system calls which have been interrupted

	static int callcnt = 0;
	// returns ok so far, used during initilisation
//	_ASSERTE(callcnt<1);
	callcnt++;
	return 0;
};

int sigemptyset(sigset_t *x)
{
	_ASSERTE(0);
	return 0;
};

unsigned sleep(unsigned int __seconds)
{
	_ASSERTE(0);
	return 0;
};

size_t strlcat (char *dst, const char *src, size_t maxlen)
{
	errno_t rc = strcat_s (dst, maxlen, src);
	_ASSERTE(rc==0); // no truncation has happened
	return strlen (dst);
};

size_t strlcpy (char *dst, const char *src, size_t maxlen)
{
	errno_t rc = strcpy_s (dst, maxlen, src);
	_ASSERTE(rc == 0); // no truncation has happened
	return strlen(dst);
};

long sysconf (int __name)
{
	_ASSERTE(0);
	return 0;
};

int tcgetattr(int x, struct termios *xx)
{
	_ASSERTE(0);
	return 0;
};

int tcsetattr(int x, int xx, const struct termios *xxx)
{
	_ASSERTE(0);
	return 0;
};

char *ttyname(int __fildes)
{
	return NULL;
};

pid_t waitpid(pid_t __pid, __wait_status_ptr_t __status, int __options)
{
	return 0;
}