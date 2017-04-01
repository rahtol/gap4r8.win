#include <crtdbg.h>
#include <windows.h>
#include "bec_timer.h"


int  timer_create(clockid_t clock_id, struct sigevent *__restrict evp, timer_t *__restrict timerid)
{
	return -1; // not yet supported
	//SetTimer
};

int timer_settime(timer_t timerid, int flags, const struct itimerspec *__restrict value, struct itimerspec *__restrict ovalue)
{
	_ASSERTE(0);
	return 0;
};

