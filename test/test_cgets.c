#include <stdio.h>
#include <string.h>

int main(void)
{
	char buffer[83];
	char *result;
	size_t bytesRead;
	int prompt = 0;

	printf ("Input line of text, followed by carriage return:\n");

	while (1) {
		printf("%d> ", ++prompt);
		fflush(stdin);
		result = gets_s (buffer, sizeof(buffer));
		if (!result)
		{
			printf("An error occurred reading from stdin: error code %d\n", errno);
			break;
		}
		else
		{
			bytesRead = strlen(buffer);
			printf("Line length=%d, Text=\"%s\"\n", bytesRead, buffer);
		}

		if (bytesRead == 1) break;
	}
}
