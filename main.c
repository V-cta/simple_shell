#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int ac, char **argv){
    char *prompt = "(simple_shell) $ ";
     char *lineptr;
     size_t n = 0; 

  /* declaring void variables */
    (void)ac; (void)argv;

    /* create an infinite loop */
    while (1){
    printf("%s", prompt);
    getline(&lineptr, &n, stdin);
    printf("%s\n", lineptr);

    free(lineptr);
    }
    
    return (0);
}
