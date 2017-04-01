#include <stdio.h>
#include "src/system.h"

extern int becmain(int argc, char *argv[], char *envp[]);

typedef struct bag2 { Bag b; } Bag2;
Bag2 dummy;

int main(int argc, char *argv[], char **envp)
{
	return becmain (argc, argv, envp);
}

