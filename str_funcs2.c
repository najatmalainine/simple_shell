#include "shell.h"

/**
 * f_strlen - it returns the token's stright length
 * @s: the token
 * @p: the position of the index in the command
 * @d: the delimeter
 * Return: the length of the token
 */
int f_strlen(char *s, int p, char d);
{
	int length = 0;

	while ((s[p] != d) && (s[p] != '\0'))
	{
		p++;
		length++;
	}
	return (length);
}
