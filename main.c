#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int ac, char **argv){
    char *prompt = "(simple_shell) $ ";
     char *prtdline = NULL, *prtdline_copy = NULL;
     size_t n = 0; 
     ssize_t read_char;
     const char *delim = " \n"
     int num_tokens = 0;
     char *token;
     int i;

  /* declaring void variables */
    (void)ac;

    /* create an infinite loop */
    while (1){
    printf("%s", prompt);
    read_char = getline(&prtdline, &n, stdin);
    /*if getline function fails or reaches EOF or user use CTRL + D */
    	if (read_char== -1){
		printf("You are about to exit shell....\n");
		return (-1);
	}
    /* allocating space for a copy of the prtdline */
	prtline_copy - malloc(sizeof(char) * read_char);
	if (prtline_copy==NULL){
		perror("tsh: memory allocation error");
		return(-1);
	}
	/*copy prtline to prtline_copy*/
	strcpy(prtline_copy, prtline);

	/********** split the string (lineptr) into an array of words ********/
        /* calculate the total number of tokens */
	token = strtok(prtline,delim);

	while (token != NULL){
		num_tokens++;
		token = strtok(NULL,delim);
	}
	num_tokens++;

	/*Allocated spacefor holding the array of strings */
	argv = malloc(sizeof(char *)* num_tokens);

	/* Storing each token in the argv array */
	token = strtok(prtline_copy, delim);

	for (i=0; token != NULL; i++){
		avg[i] = malloc(sizeof(char) * strlen(token));
		strcpy(avgv[i], token);

		token = strtok(NULL,delim0;
				}
				avgv[i] = NULL;

    printf("%s\n", prtdline);

    /*clear allocated memory*/

    free(prtdline);

   }
    
    return (0);
}
