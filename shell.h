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

char *takein_space(char *s);
char **_strtok(char *s, char *d);
char **f_strtok(char *s, char *d);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int prints_prompt(char **ev);
void *_realloc(void *ptr, unsigned int size_old, unsigned int size_new);
size_t _getline(char **str);
int f_strlen(char *s, int p, char d);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _cd(char **cmd, list_t *envi, int n);
int _builtin(char **tkn, list_t *envi, int n, char **cmd);
void non_interactive(list_t *enm);
char *_which(char *s, list_t *envi);
int ___exit(char **s, list_t *envi, int n, char **cmd);
int _execve(char **c, list_t *envi, int n);
void free_db(char **s);
int node_index_rm(list_t **hd, int index);
int _unsetenv(list_t **envi, char **s);
int _setenv(list_t **envi, char **s);
int f_envi(list_t *envi, char *s);
void free_linked_list(list_t *list);
int _enm(char **s, list_t *enm);
char *_getenv(char *s, list_t *envi);
list_t *enm_linked_list(char **enm);
list_t *add_end_node(list_t **hd, char *s);
size_t prints_linked_list(list_t *l);
void not_found(char *s, int c_no, list_t *enm);
void cmd_invalid(char *s, int c_no, list_t *enm);
void invalid_number(char *s, int c_no, list_t *enm);
char *int_to_string(int num);


#endif
