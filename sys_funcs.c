#include "shell.h"

/**
 * _which - finds command by appending it to a matching PATH directory
 * @s: the first command user typed
 * @envi: environmental variable
 * Return: a copy of the command
 */
char *_which(char *s, list_t *envi)
{
	char *path, *buf = NULL, **tokens;
	int i = 0;

	path = get_env("PATH", envi);
	tokens = c_strtok(path, ":");
	free(path);

	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] == '\0')
			buf = getcwd(buf, 0);
		else
			buf = _strdup(tokens[i]);
		buf = _strcat(buf, "/");
		buf = _strcat(buf, s);
		if (access(buf, F_OK) == 0)
		{
			free_db(tokens);
			return (buf);
		}
		free(buf);
		i++;
	}
	free_db(tokens);
	return (s);
}

/**
 * f_exit - it frees the user's command and linked list
 * @str: user's command
 * @envi: envirnment variable
 */
void f_exit(char **str, list_t *envi)
{
	free_db(str);
	free_linked_list(envi);
	_exit(0);
}
