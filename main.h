#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} shelldata;

/**
 * struct separators_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct separators_list_s
{
	char separator;
	struct separators_list_s *next;
} separators_list;

/**
 * struct cmd_lines_lnklist_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct cmd_lines_lnklist_s
{
	char *line;
	struct cmd_lines_lnklist_s *next;
} cmd_lines_lnklist;

/**
 * struct variables_lnklist_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct variables_lnklist_list
{
	int len_var;
	char *val;
	int len_val;
	struct variables_lnklist_list *next;
} variables_lnklist;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(shelldata *datash);
} builtint;

/* aux_lists.c */
separators_list *add_sep_node_end(separators_list **head, char sep);
void free_separators_list(separators_list **head);
cmd_lines_lnklist *add_line_node_end(cmd_lines_lnklist **head, char *line);
void free_cmd_lines_lnklist(cmd_lines_lnklist **head);

/* aux_lists2.c */
variables_lnklist *add_rvar_node(variables_lnklist **head, int lvar, char *var, int lval);
void free_rvar_list(variables_lnklist **head);

/* aux_str functions */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

/* aux_mem.c */
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* aux_str2.c */
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

/* aux_str3.c */
void rev_string(char *s);

/* check_syntax_error.c */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(shelldata *datash, char *input, int i, int bool);
int check_syntax_error(shelldata *datash, char *input);

/* shell_loop.c */
char *without_comment(char *in);
void shell_loop(shelldata *datash);

/* read_line.c */
char *read_line(int *i_eof);

/* split.c */
char *swap_char(char *input, int bool);
void add_nodes(separators_list **head_s, cmd_lines_lnklist **head_l, char *input);
void go_next(separators_list **list_s, cmd_lines_lnklist **list_l, shelldata *datash);
int split_commands(shelldata *datash, char *input);
char **split_line(char *input);

/* rep_var.c */
void check_env(variables_lnklist **h, char *in, shelldata *data);
int check_vars(variables_lnklist **h, char *in, char *st, shelldata *data);
char *replaced_input(variables_lnklist **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, shelldata *datash);

/* get_line.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int exec_line(shelldata *datash);

/* cmd_exec.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(shelldata *datash);
int check_error_cmd(char *dir, shelldata *datash);
int cmd_exec(shelldata *datash);

/* env1.c */
char *_getenv(const char *name, char **_environ);
int _env(shelldata *datash);

/* env2.c */
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, shelldata *datash);
int _setenv(shelldata *datash);
int _unsetenv(shelldata *datash);

/* cd.c */
void cd_dot(shelldata *datash);
void cd_to(shelldata *datash);
void cd_previous(shelldata *datash);
void cd_to_home(shelldata *datash);

/* cd_shell.c */
int cd_shell(shelldata *datash);

/* get_builtin */
int (*get_builtin(char *cmd))(shelldata *datash);

/* _exit.c */
int exit_shell(shelldata *datash);

/* aux_stdlib.c */
int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

/* aux_error1.c */
char *strcat_cd(shelldata *, char *, char *, char *);
char *error_get_cd(shelldata *datash);
char *error_not_found(shelldata *datash);
char *error_exit_shell(shelldata *datash);

/* aux_error2.c */
char *error_get_alias(char **args);
char *error_env(shelldata *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(shelldata *datash);


/* get_error.c */
int get_error(shelldata *datash, int eval);

/* get_sigint.c */
void get_sigint(int sig);

/* aux_help.c */
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

/* aux_help2.c */
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

/* get_help.c */
int get_help(shelldata *datash);

#endif

