#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct list - environment variables' linked list
 * @var: string for environment variable
 * @next: next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

int prints_prompt(char **env);
void *_realloc(void *ptr, unsigned int size_old, unsigned int size_new);
size_t _getline(char **str);
int f_strlen(char *s, int p, char d);
char *takein_space(char *str);
char **_strtok(char *str, char *delm);
char **f_strtok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _cd(char **cmd, list_t *envi, int n);
int _builtin(char **token, list_t *env, int num, char **command);
void non_interactive(list_t *env);
char *_which(char *str, list_t *envi);
int ___exit(char **s, list_t *envi, int n, char **cmd);
int _execve(char **c, list_t *envi, int n);
void free_db(char **str);
void free_linked_list(list_t *list);
int _enm(char **str, list_t *env);
char *_getenv(char *str, list_t *env);
list_t *enm_linked_list(char **env);
list_t *add_end_node(list_t **head, char *str);
size_t prints_linked_list(list_t *l);
int node_index_rm(list_t **head, int index);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);
int f_envi(list_t *env, char *str);
void not_found(char *str, int num, list_t *env);
void cmd_invalid(char *str, int c_n, list_t *env);
void invalid_number(char *str, int c_n, list_t *env);
char *int_to_string(int num);


#endif
