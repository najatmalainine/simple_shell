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
	return (c_strdup(envi->var, n));
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
