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
/**
 * ___exit - it frees the user 's input and then exits
 * @s: user's command
 * @envi: environmental variable
 * @n: nth user command line
 * @cmd: the command to free
 * Return: 0 if it successeds 2 if it fails
 */
int ___exit(char **s, list_t *envi, int n, char **cmd)
{
	int value = 0;

	if (s[1] != NULL)
		value = _atoi(s[1]);

	if (value == -1)
	{
		invalid_number(s[1], n, envi);
		free_db(s);
		return (2);
	}
	free_db(s);
	free_linked_list(envi);
	if (cmd != NULL)
		free_db(cmd);
	exit(value);
}
