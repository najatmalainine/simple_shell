#include "shell.h"


/**
 * f_strdup - duplicates string excluding beginning bytes
 * @s: the string to duplicate
 * @num: number of bytes to exclude (e.g. excludes "PATH=")
 * Return: string (e.g. /bin:/bin/ls)
 */
char *f_strdup(char *s, int num)
{
	char *dup;
	int i, len = 0;

	if (s == NULL)
		return (NULL);

	while (*(s + len))
		len++;
	len++;

	dup = malloc(sizeof(char) * (len - num));
	if (dup == NULL)
		return (NULL);

	i = 0;
	while (i < (len - num))
	{
		*(dup + i) = *(s + num + i);
		i++;
	}
	return (dup);
}

/**
 * _getenv - looks for a copy of the environment variable
 * @s: string to store it in
 * @envi: entire set of environmental variables
 * Return: copy of requested environmental variable
 */
char *_getenv(char *s, list_t *envi)
{
	int i = 0, n = 0;

	while (envi != NULL)
	{
		i = 0;
		while ((envi->var)[i] == s[i])
			i++;
		if (s[i] == '\0' && (envi->var)[i] == '=')
			break;
		envi = envi->next;
	}

	while (s[n] != '\0')
		n++;
	n++;
	return (f_strdup(envi->var, n));
}

/**
 * f_envi - it finds environment variable
 * @envi: environment variable
 * @s: variable name
 * Return: the index of the node
 */
int f_envi(list_t *envi, char *s)
{
	int i = 0, idx = 0;

	while (envi != NULL)
	{
		i = 0;
		while ((envi->var)[i] == s[i])
			i++;
		if (s[i] == '\0')
			break;
		envi = envi->next;
		idx++;
	}
	if (envi == NULL)
		return (-1);
	return (idx);
}

/**
 * _unsetenv - it removes node in environment variable
 * @envi: linked list
 * @s: the user's command
 * Return: 0 on success
 */
int _unsetenv(list_t **envi, char **s)
{
	int idx = 0, i = 0;

	if (s[1] == NULL)
	{
		write(STDOUT_FILENO, "Few arguments\n", 18);
		free_db(s);
		return (-1);
	}
	idx = f_envi(*envi, s[1]);
	free_db(s);
	if (idx == -1)
	{
		write(STDOUT_FILENO, "Can't find\n", 12);
		return (-1);
	}
	i = node_index_r(envi, idx);
	if (i == -1)
	{
		write(STDOUT_FILENO, "Can't find\n", 12);
		return (-1);
	}
	return (0);
}

/**
 * _setenv - it creates/modify existing environment variable
 * @envi: environment variable
 * @s: the user's command
 * Return: 0 on success, 1 on fail
 */
int _setenv(list_t **envi, char **s)
{
	int idx = 0, i = 0;
	char *cat;
	list_t *hol;

	if (s[1] == NULL || s[2] == NULL)
	{
		write(STDOUT_FILENO, "Few arguments\n", 18);
		free_db(s);
		return (-1);
	}
	cat = _strdup(s[1]);
	cat = _strcat(cat, "=");
	cat = _strcat(cat, s[2]);
	idx = f_envi(*envi, s[1]);
	if (idx == -1)
	{
		add_end_node(envi, cat);
	}
	else
	{
		hol = *envi;
		while (i < idx)
		{
			hol = hol->next;
			i++;
		}
		free(hol->var);
		hol->var = _strdup(cat);
	}
	free(cat);
	free_db(s);
	return (0);
}
