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
