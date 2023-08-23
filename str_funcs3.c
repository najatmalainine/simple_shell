#include "shell.h"

/**
 * c_size - it returns the number of delimeters
 * @s: the user's command
 * @d: the delimeter
 * Return: number of tokens
 */
int c_size(char *s, char d)
{
	int j = 0, delm_no = 0;

	while (s[j] != '\0')
	{
		if (s[j] == d)
		{
			delm_no++;
		}
		j++;
	}
	return (delm_no);
}
