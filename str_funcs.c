#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int len1 = 0;
	int len2 = 0;
	int tot_len = 0;
	int i = 0;


	while (dest[len1] != '\0')
	{
		len1++;
		tot_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		tot_len++;
	}


	dest = _realloc(dest, len1, sizeof(char) * tot_len + 1);

	while (src[i] != '\0')
	{
		dest[len1] = src[i];
		len1++;
		i++;
	}
	dest[len1] = '\0';

	return (dest);
}
