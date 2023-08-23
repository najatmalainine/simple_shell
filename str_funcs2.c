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

/**
 * f_size - It returns the number of delimeters
 * @s: the command
 * @d: the delimeter
 * Return: the number of delimeters
 */

int f_size(char *s, char d)
{
	int j = 0, delm_no = 0;

	while (s[j] != '\0')
	{
		if ((s[j] == d) && (s[j + 1] != d))
		{
			delm_no++;
		}
		if ((s[j] == d) && (s[j + 1] == '\0'))
		{
			delm_no--;
		}
		j++;
	}
	return (delm_no);
}

