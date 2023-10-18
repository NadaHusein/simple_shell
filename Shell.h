#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
/*for read and write */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining flags */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_PIPE	3
/* numeric conversion */
#define CONVERT_LOWERCASE
#define CONVERT_UNSIGNED

/* if using system getline() call*/
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE ".s_shellHist"
#define HIST_MAX 4096

extern char **environ;
/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;
/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *					allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last executed command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining is enabled
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct command_Args
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to command ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} args_t;

#define ARGS_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function to be exectued
 */
typdef struct builtin 
{
 char *type;
 int (*func)(args_t *);

} command_table;

/*err_string_functions.c*/
void _errorputs(char *);
int _errorputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/*string_functions.c*/
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
/*string_functions2.c*/
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
/*string_functions3.c*/
char *_strncpy(char *, char * , int);
char *_strncat (char *, char *, int);
char *_strchr(char*, char);
/*string_functions4.c*/
char **strtoword(char *, char *);
char **strtoword2(char *, char);
/*memory_functions.c*/
char *_memset(char *s, char b, unsigned int n);
void ffree(char **string_list);
void *_realloc(void *ptr, int);
int pointer_free(void **ptr);
/*helpers.c*/
int interactive(args_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

/*helpers2.c*/
int _erratoi(char *s);
void print_error(args_t*info, char *estr);
int print_d(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);

/*liststr.c*/
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_string(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);


/*liststr2.c*/
size_t list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);

/*info_handler.c*/
void clear_info(args_t *info);
void set_info(args_t *info, char **av);
void free_info(args_t *info, int all);

/*error_string_handlers.c*/
void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
/*env.c*/
int myenv(args_t *info);
char *_getenv(args_t *info, const char *name);
int setenv(args_t *info);
int unsetenv(args_t *info);
int populate_env_list(args_t *info);
/*env2.c*/
char **get_environ(args_t *info);
int _unsetenv(args_t *info, char *var);
int _setenv(args_t *info, char *var, char *value);
/*file_writTo_functions.c*/
char *get_history_file(args_t *info);
int write_history( args_t *info);
int read_history(args_t *info);
int build_history_list(args_t *info, char *buf, int linecount);
int renumber_history(args_t *info);
/*hshell.c*/
int interactive_hsh(args_t *info, char **av);
int find_builtin(args_t *info);
void find_cmd(args_t *info);
void fork_cmd(args_t *info);
/*getline.c*/
ssize_t input_buf(args_t *info, char **buf, size_t *len);
ssize_t get_input(args_t *info);
ssize_t read_buf(args_t *info, char *buf, size_t *i);
int _getline(args_t *info, char **ptr, size_t *length);
void sigintHandler(__attribute__((unused))int sig_num);
/*emulator_builtin.c*/
int _myexit(args_t *);
int _mycd(args_t *);
int _myhelp(args_t *);



/*emulator_builtin2.c*/
int _myhistory(info_t *);
int _myalias(info_t *);




















#endif
