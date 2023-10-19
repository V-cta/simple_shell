#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * main - Entry point for the shell program.
 * Return: 0 on success, -1 on failure.
 */

int main(void)
{
    char *prompt = "(simple_shell) $ ";
    char *prtdline = NULL, *prtdline_copy = NULL;
    size_t n = 0;
    ssize_t read_char;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;

    /* create an infinite loop */
    while (1)
    {
        printf("%s", prompt);
        read_char = getline(&prtdline, &n, stdin);
        /* if getline function fails or reaches EOF or user uses CTRL + D */
        if (read_char == -1)
        {
            printf("You are about to exit shell....\n");
            free(prtdline);
            return (-1);
        }
        /* allocating space for a copy of the prtdline */
        prtdline_copy = malloc(sizeof(char) * read_char + 1);
        if (prtdline_copy == NULL)
        {
            perror("tsh: memory allocation error");
            return (-1);
        }
        /* copy prtdline to prtdline_copy */
        strcpy(prtdline_copy, prtdline);
        /********** split the string (prtdline) into an array of words ********/
        /* calculate the total number of tokens */
        token = strtok(prtdline, delim);
        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }

        /* Allocated space for holding the array of strings */
        char **avg = malloc(sizeof(char *) * (num_tokens + 1));
        /* Storing each token in the argv array */
        token = strtok(prtdline_copy, delim);
        for (i = 0; token != NULL; i++)
        {
            avg[i] = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(avg[i], token);
            token = strtok(NULL, delim);
        }
        avg[i] = NULL;
        /* execute the command using cmdexe(avg); */
        for (i = 0; avg[i] != NULL; i++)
        {
            free(avg[i]);
        }
        free(avg);
        free(prtdline_copy);
    }

    free(prtdline);
    return (0);
}
