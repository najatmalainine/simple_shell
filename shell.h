#ifndef  SHELL
#define SHELL

#include <signal.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <wait.h>

/**
 * struct list - Structure linked list
 * @vr: String of enviromental variables
 * @nxt: A pointer to the next node available
 */
typedef struct list
{
	char *vr;
	struct list *nxt;

} list_t;

/* All the functions prototypes for the simple_shell project */
void invalid_number(list_t *enm, char *s, int c_no);
void not_found(char *s, int c_no, list_t *enm);
void cmd_invalid(list_t *enm, int c_no, char *s);
void ctrl_d(int c, char *cmd, list_t *enm);
void _ctrl_c(int num);
void *_realloc(void *ptr, unsigned int size_old, unsigned int size_new);
void f_exit(char **str, list_t *envi);
void cd_home(list_t *envi, char *cur);
void non_interactive(list_t *enm);
void free_db(char **s);
int _builtin(char **tkn, list_t *envi, int n, char **cmd);
int prints_prompt(char **ev);
int cd_exec(list_t *envi, char *cur, char *dir, char *str, int n);
int _execve(char **c, list_t *envi, int n);
int f_setenv(list_t **envi, char *name, char *dir);
int _cd(char **cmd, list_t *envi, int n);
int _atoi(char *s);
int _enm(char **s, list_t *enm);
int ___exit(char **s, list_t *envi, int n, char **cmd);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *takein_space(char *s);
char *ignore_c(char *s);
char *_strcat(char *dest, char *src);
char *_which(char *s, list_t *envi);
char *f_strcat(char *dest, char *src);
size_t _getline(char **str);
list_t *enm_linked_list(char **enm);


#endif

