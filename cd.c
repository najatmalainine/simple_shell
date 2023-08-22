#include "shell.h"

/**
 * f_strcat - concatenate two strings ignoring the first character
 * @dest: destination string
 * @src: the string to append
 * Return: the concatenated string
 */
char *f_strcat(char *dest, char *src)
{
	int len = 0;
	int len2 = 0;
	int tot_len = 0;
	int i = 0;

	while (dest[len] != '\0')
	{
		len++;
		tot_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		tot_len++;
	}

	dest = _realloc(dest, len, sizeof(char) * tot_len + 1);

	i = 1;
	while (src[i] != '\0')
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';

	return (dest);
}

/**
 * f_setenv - _setenv that concatenates the string first before setting
 * @envi: environmental variable
 * @name: environmental variable name
 * @dir: directory path
 * Return: 0 if success
 */
int f_setenv(list_t **envi, char *name, char *dir)
{
	char *cat;
	list_t *hol;
	int idx = 0, i = 0;

	cat = _strdup(name);
	cat = _strcat(cat, "=");
	cat = _strcat(cat, dir);
	idx = f_envi(*envi, name);

	hol = *envi;
	while (i < idx)
	{
		hol = hol->next;
		i++;
	}
	free(hol->var);
	hol->var = _strdup(cat);
	free(cat);
	return (0);
}
/**
 * cd_home - move to the home directory
 * @envi: environment variable
 * @cur: current working directotry
 */
void cd_home(list_t *envi, char *cur)
{
	char *home = NULL;

	home = _getenv("home", envi);
	f_setenv(&envi, "pwd_old", cur);
	free(cur);
	if (access(home, F_OK) == 0)
		chdir(home);
	cur = NULL;
	cur = getcwd(cur, 0);
	f_setenv(&envi, "pwd", cur);
	free(cur);
	free(home);
}
/**
 * cd_exec - executing the cd command
 * @envi: environmental variable
 * @cur: the current working directotry
 * @dir: directory path
 * @str: the 1st argument to write out error
 * @n: the line number
 * Return: 0 if success 2 if fail
 */
int cd_exec(list_t *envi, char *cur, char *dir, char *str, int n)
{
	int j = 0;

	if (access(dir, F_OK) == 0)
	{
		f_setenv(&envi, "pwd_old", cur);
		free(cur);
		chdir(dir);
		cur = NULL;
		cur = getcwd(cur, 0);
		f_setenv(&envi, "pwd", cur);
		free(cur);
	}
	else
	{
		cmd_invalid(str, n, envi);
		free(cur);
		j = 2;
	}
	return (j);
}
/**
 * _cd - change directory
 * @cmd: the user's command
 * @envi: enviromental variable
 * @n: the nth user's command
 * Return: 0 if success 2 if failed
 */
int _cd(char **cmd, list_t *envi, int n)
{
	char *cur = NULL, *dir = NULL;
	int exit_stat = 0;

	cur = getcwd(cur, 0);
	if (cmd[1] != NULL)
	{
		if (cmd[1][0] == '~')
		{
			dir = _getenv("home", envi);
			dir = f_strcat(dir, cmd[1]);
		}
		else if (cmd[1][0] == '-')
		{
			if (cmd[1][1] == '\0')
				dir = _getenv("pwd_old", envi);
		}
		else
		{
			if (cmd[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, cmd[1]);
			}
			else
				dir = _strdup(cmd[1]);
		}
		exit_stat = cd_exec(envi, cur, dir, cmd[1], n);
		free(dir);
	}
	else
		cd_home(envi, cur);
	free_db(cmd);
	return (exit_stat);
}
