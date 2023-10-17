#include "main.h"

void cmdexe(char **argv)
{
	char *command = NULL;
	if (argv)
	{
		/* get the command */
		command = argv[0];
		/* execute the command with execve */
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		};
	}
}
