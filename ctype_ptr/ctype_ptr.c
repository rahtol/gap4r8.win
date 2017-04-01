#include <stdio.h>

extern __IMPORT char *__ctype_ptr__;

void main ()
{
	int c;
	
	for (c=0;c<257;c++) {
		printf ("%3u, ", (unsigned char)__ctype_ptr__[c]);
		if (c%16 ==0) printf("\n");
	}
}