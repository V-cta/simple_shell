#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

int main(int ac)
{
	char *prompt = "(simple_shell) $ ";
	char *prtdline = NULL, *prtdline_copy = NULL;
	size_t n = 0;
	ssize_t read_char;
	const char *delim = " \n";

	/* declaring void variables */
	(void)ac;

    /* create an infinite loop*/
	while (1)
	{
		printf("%s", prompt);
		read_char = getline(&prtdline, &n, stdin);
		/* if getline function fails or reaches EOF or user uses CTRL + D*/
		if (read_char == -1)
		{
			printf("You are about to exit the shell....\n");
			free(prtdline);
			return (-1);
		}
		/* allocating space for a copy of the prtdline*/
		prtdline_copy = malloc(sizeof(char) * read_char + 1);
		if (prtdline_copy == NULL;
				{
				perror("tsh: memory allocation error");
				return (-1);
				}
				/*copy prtdline to prtdline_copy*/
				strcpy(prtdline_copy, prtdline);
				/*split the string (prtdline) into an array of words*/
				char **argv = NULL;
				char *token;
				int num_tokens = 0;
				token = strtok(prtdline, delim);
				while (token != NULL)
				{
				num_tokens++;
				token = strtok(NULL, delim);
				}
				/*Allocate space for holding the array of strings*/
				argv = malloc(sizeof(char *) * (num_tokens + 1));
				/* Storing each token in the argv array*/
				token = strtok(prtdline_copy, delim);
				int i = 0;
				while (token != NULL)
				{
					argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
					strcpy(argv[i], token);
					token = strtok(NULL, delim);
					i++;
				}
				argv[i] = NULL;
				/* Execute the command*/
				execmd(argv);
				/*Free allocated memory*/
				for (i = 0; i < num_tokens; i++)
				{
					free(argv[i]);
				}
				free(argv);
				free(prtdline_copy);
	}
	free(prtdline);
	return (0);
}
