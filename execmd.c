#include "main.h"
#include "map_location.c"

/**
 * cmdexe - Execute a command with given arguments.
 * @argv: An array of strings containing the command and its arguments.
 */
void cmdexe(char **argv)
{
	if (argv)
	{
		char *command = NULL;
		char *actual_command = NULL;

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
