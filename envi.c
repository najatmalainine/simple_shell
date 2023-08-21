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
