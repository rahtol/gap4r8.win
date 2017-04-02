#pragma once

#define _BEC_

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include <crtdbg.h>
#include <stdio.h>

size_t strlcat(char *dst, const char *src, size_t maxlen);
size_t strlcpy(char *dst, const char *src, size_t maxlen);

char *realpath(const char *__restrict path, char *__restrict resolved_path);

struct tms {
	clock_t	tms_utime;		/* user time */
	clock_t	tms_stime;		/* system time */
	clock_t	tms_cutime;		/* user time, children */
	clock_t	tms_cstime;		/* system time, children */
};

clock_t times(struct tms *x);

typedef long off_t;

#define PROT_NONE 0
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_EXEC 4

#define MAP_PRIVATE 2
#define MAP_ANONYMOUS 0x20
#define MAP_ANON MAP_ANONYMOUS
#define MAP_FAILED ((void *)-1)

void *mmap (void *__addr, size_t __len, int __prot, int __flags, int __fd, off_t __off);
int munmap (void *__addr, size_t __len);
void *sbrk (ptrdiff_t __incr);

unsigned sleep(unsigned int __seconds);

double exp10(double x);

struct timeval
{
	long tv_sec;
	long tv_usec;
};

int gettimeofday(struct timeval *__restrict __p, void *__restrict __tz);

#define RUSAGE_SELF 0

struct rusage {
	struct timeval ru_utime;
	long dummy[64];
};

int getrusage(int __who, struct rusage *__rusage);

#define NAME_MAX 255

typedef unsigned int __uint32_t;
typedef unsigned long long __uint64_t;
typedef __uint32_t uint32_t;

struct dirent
{
	uint32_t __d_version;			/* Used internally */
	__uint64_t d_ino;
	unsigned char d_type;
	unsigned char __d_unused1[3];
	__uint32_t __d_internal1;
	char d_name[NAME_MAX + 1];
};

typedef struct __DIR
{
	unsigned long __d_cookie;
	struct dirent *__d_dirent;
	char *__d_dirname;
	int __d_position;
	int __d_fd;
	intptr_t __d_internal;
	void *__handle;
	void *__fh;
	unsigned __flags;
} DIR;

DIR *opendir(const char *pathname);
struct dirent *readdir(DIR *d);
int closedir(DIR *d);

typedef long ssize_t;

#define RTLD_GLOBAL 4

void *dlopen(const char *x, int xx);
int dlclose(void *x);
void *dlsym(void *x, const char *xx);
char *dlerror(void);

int	pclose(FILE *x);
FILE *popen(const char *x, const char *xx);

typedef unsigned char cc_t;
typedef unsigned int  tcflag_t;
typedef unsigned int  speed_t;

#define TCSANOW		2

#define IGNBRK	0x00001
#define BRKINT	0x00002
#define IGNPAR	0x00004
#define IMAXBEL	0x00008
#define INPCK	0x00010
#define ISTRIP	0x00020
#define INLCR	0x00040
#define IGNCR	0x00080
#define ICRNL	0x00100
#define IXON	0x00400
#define IXOFF	0x01000
#define IUCLC	0x04000
#define IXANY	0x08000
#define PARMRK	0x10000

#define ISIG	0x0001
#define ICANON	0x0002
#define ECHO	0x0004
#define ECHOE	0x0008
#define ECHOK	0x0010
#define ECHONL	0x0020
#define NOFLSH	0x0040
#define TOSTOP	0x0080
#define IEXTEN	0x0100
#define FLUSHO	0x0200
#define ECHOKE	0x0400
#define ECHOCTL	0x0800

#define VDISCARD	1
#define VEOL		2
#define VEOL2		3
#define VEOF		4
#define VERASE		5
#define VINTR		6
#define VKILL		7
#define VLNEXT		8
#define VMIN		9
#define VQUIT		10
#define VREPRINT	11
#define VSTART		12
#define VSTOP		13
#define VSUSP		14
#define VSWTC		15
#define VTIME		16
#define VWERASE	17

#define NCCS		18

struct termios
{
	tcflag_t	c_iflag;
	tcflag_t	c_oflag;
	tcflag_t	c_cflag;
	tcflag_t	c_lflag;
	char		c_line;
	cc_t		c_cc[NCCS];
	speed_t	c_ispeed;
	speed_t	c_ospeed;
	long dummy[64];
};

int tcgetattr(int x, struct termios *xx);
int tcsetattr(int x, int xx, const struct termios *xxx);

int siginterrupt(int x, int xx);

#define	F_OK	0
#define	R_OK	4
#define	W_OK	2
#define	X_OK	1

#define	S_ISBLK(m)	(((m)&S_IFMT) == 0xffff)
#define	S_ISCHR(m)	(((m)&S_IFMT) == S_IFCHR)
#define	S_ISDIR(m)	(((m)&S_IFMT) == S_IFDIR)
#define	S_ISFIFO(m)	(((m)&S_IFMT) == 0xffff)
#define	S_ISREG(m)	(((m)&S_IFMT) == S_IFREG)
#define	S_ISLNK(m)	(((m)&S_IFMT) == 0xffff)
#define	S_ISSOCK(m)	(((m)&S_IFMT) == 0xffff)

int lstat(const char *__restrict __path, struct stat *__restrict __buf);
char *mkdtemp(char *);
int mkstemp(char *);

/*
libraries required
libucrtd.lib
LIBCMTD.lib
libvcruntimed.lib
kernel32.lib
OLDNAMES.lib
uuid.lib
*/

