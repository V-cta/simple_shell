#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char *map_location(char *command)
{
	char *map, *map_copy, *map_token, *file_map;
	int command_length, directory_length;
	struct stat buffer;
	map = getenv("PATH");
	if (map)
	{
		/* Duplicate the path string -> remember to free up memory for this because strdup allocates memory that needs to be freed*/
		map_copy = strdup(map);
		/* Get length of the command that was passed */
		command_length = strlen(command);
		/* Let's break down the path variable and get all the directories available*/
		map_token = strtok(map_copy, ":");
		while (map_token != NULL)
		{
			/* Get the length of the directory*/
			directory_length = strlen(map_token);
			/* allocate memory for storing the command name together with the directory name */
			file_map = malloc(command_length + directory_length + 2);
			/* NB: we added 2 for the slash and null character we will introduce in the full command */
			/* to build the path for the command, let's copy the directory path and concatenate the command to it */
			strcpy(file_map, map_token);
			strcat(file_map, "/");
			strcat(file_map, command);
			/* let's test if this file path actually exists and return it if it does, otherwise try the next directory */
			if (stat(file_map, &buffer) == 0)
			{
				/* return value of 0 means success implying that the file_path is valid*/
				/* free up allocated memory before returning your file_path */
				free(map_copy);
				return (file_map);
			}
			else
			{
				/* free up the file_path memory so we can check for another path*/
				free(file_map);
				map_token = strtok(NULL, ":");
			}
		}
		/* if we don't get any file_path that exists for the command, we return NULL but we need to free up memory for path_copy */
		free(map_copy);
		/* before we exit without luck, let's see if the command itself is a file_path that exists */
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
