#include "main.h"
#include "map_location.c"

void cmdexe(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	if (argv)
	{
		/* get the command */
		command = argv[0];
		/* generate the path to this command before passing it to execve */
		actual_command = map_location(command);
		/* execute the command with execve */
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error:");
			 exit(EXIT_FAILURE);
		};
	}
}
