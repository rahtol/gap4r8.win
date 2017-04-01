#include <time.h>
#include <crtdbg.h>

clock_t times(struct tms *x)
{
	struct timespec t;

	_ASSERTE(x != NULL);

	timespec_get (&t, TIME_UTC);
	x->tms_utime = t.tv_sec * 1000L + t.tv_nsec / 1000000L;
	x->tms_stime = x->tms_utime;
	return 0;
};

