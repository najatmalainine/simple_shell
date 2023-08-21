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

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: int that tells num spaces in between
 */

int _strcmp(char *s1, char *s2)
{
	/* while neither strings have ended*/
	while (*s1 != '\0' || *s2 != '\0')
	{
		/* if element in arr1 in arr2 are diff, return difference*/
		if (*s1 != *s2)
			return (*s1 - *s2);
		/* iterate index*/
		s1++;
		s2++;
	}
	return (0);
}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: destination string
 * @src: the string to copy
 * Return: copy of original source
 */

char *_strcpy(char *dest, char *src)
{
	int i;
	int length = 0;

	while (src[length] != '\0')
	{
		length++;
	}

	for (i = 0; i <= length; i++)
		dest[i] = src[i];

	return (dest);
}
