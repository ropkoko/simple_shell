#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("simple_shell$");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0)
		{
			continue;
		}
		char status = system(command);

		if (status == -1)
		{
			printf("Error executing the command.\n");
		}
		else if (status != 0)
		{
			printf("command '%s' not found\n", command);
		}
	}
	return (0);
}
