#include <stdio.h>
#include <string.h>

char *bec_getline(int fid, char *line, int length)
{
	char *p;
//	fflush(stdin);
	p = fgets (line, length, stdin);
//	strcat_s(line, length, "\x0d\x0a");
//	printf("%s\n", line);
//	for (int i = 0; line[i] != 0; i++) printf("%02x ",line[i]); printf("\n");
	return line;
}
