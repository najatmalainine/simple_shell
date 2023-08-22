#include "shell.h"

/**
 * _atoi - converts string to int
 * @s: string
 * Return: integer
 */
int _atoi(char *s)
{
	unsigned int num = 0;
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		if (s[i] > '9' || s[i] < '0')
			return (-1);
		i++;
	}
	return (num);
}
