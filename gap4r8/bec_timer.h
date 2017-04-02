#pragma once
#include <time.h>

#define	SIGVTALRM 26	/* virtual time alarm */

typedef unsigned long clockid_t;
typedef unsigned long timer_t;

#define CLOCK_REALTIME (clockid_t)1

struct itimerspec {
	struct timespec  it_interval;
	struct timespec  it_value;
};

typedef struct __pthread_attr_t { char __dummy; } *pthread_attr_t;

typedef union sigval
{
	int sival_int;			/* integer signal value */
	void  *sival_ptr;			/* pointer signal value */
} sigval_t;

typedef struct sigevent
{
	sigval_t sigev_value;			/* signal value */
	int sigev_signo;			/* signal number */
	int sigev_notify;			/* notification type */
	void(*sigev_notify_function) (sigval_t); /* notification function */
	pthread_attr_t *sigev_notify_attributes; /* notification attributes */
} sigevent_t;

enum
{
	SIGEV_SIGNAL = 0,			/* a queued signal, with an application
								defined value, is generated when the
								event of interest occurs */
	SIGEV_NONE,				/* no asynchronous notification is
							delivered when the event of interest
							occurs */
	SIGEV_THREAD				/* a notification function is called to
								perform notification */
};

int timer_create (clockid_t clock_id, struct sigevent *__restrict evp, timer_t *__restrict timerid);
int timer_settime (timer_t timerid, int flags, const struct itimerspec *__restrict value, struct itimerspec *__restrict ovalue);


#define SA_SIGINFO   2   		/* Invoke the signal catching function with three arguments instead of one */
#define SA_RESTART   0x10000000 	/* Restart syscall on signal return */
#define SA_RESETHAND 0x80000000		/* Reset to SIG_DFL on entry to handler */

typedef struct siginfo
{
	long dummy[64];
} siginfo_t;

typedef unsigned int sigset_t;
typedef void(*_sig_func_ptr)(int);
typedef void(*_sigaction_func_ptr) (int, siginfo_t *, void *);

struct sigaction
{
	_sig_func_ptr sa_handler;  		/* SIG_DFL, SIG_IGN, or pointer to a function */
	_sigaction_func_ptr sa_sigaction;
	sigset_t sa_mask;
	int sa_flags;
};

int sigemptyset(sigset_t *);
int sigaction(int x, const struct sigaction *, struct sigaction *);


