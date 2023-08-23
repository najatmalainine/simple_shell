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

/**
 * f_strtok - it tokenizes the string with empty string
 * @s: the user's command
 * @d: delimeter
 * Return: array of tokens
 */
char **f_strtok(char *s, char *d)
{
	char **tokens = NULL, ch;
	int buff_size = 0, p = 0, si = 0, j = 0, len = 0, se = 0;

	ch = d[0];
	buff_size = c_size(s, ch);
	tokens = malloc(sizeof(char *) * (buff_size + 2));
	if (tokens == NULL)
		return (NULL);

	while (s[se] != '\0')
		se++;
	while (si < se)
	{
		len = f_strlen(s, si, ch);
		tokens[p] = malloc(sizeof(char) * (len + 1));
		if (tokens[p] == NULL)
			return (NULL);
		j = 0;
		while ((s[si] != ch) &&
		       (s[si] != '\0'))
		{
			tokens[p][j] = s[si];
			j++;
			si++;
		}
		tokens[p][j] = '\0';
		p++;
		si++;
	}
	tokens[p] = NULL;
	return (tokens);
}

/**
 * num_len - it returns the number of 0s in a tens power number
 * @no: number
 * Return: number of digits
 */
int num_len(int no)
{
	int count = 0;
	int num = no;

	while (num > 9 || num < -9)
	{
		num /= 10;
		count++;
	}
	return (count);
}

/**
 * int_to_string - makes an integer into a string
 * @num: the number
 * Return: the number as a string. NULL if failed
 */

char *int_to_string(int num)
{
	int dig, tens, j = 0, m = 0, x;
	char *result;

	dig = num;
	tens = 1;

	if (num < 0)
		m = 1;
	result = malloc(sizeof(char) * (num_len(dig) + 2 + m));
	if (result == NULL)
		return (NULL);
	if (num < 0)
	{
		result[j] = '-';
		j++;
	}
	for (x = 0; dig > 9 || dig < -9; x++)
	{
		dig /= 10;
		tens *= 10;
	}
	for (dig = num; x >= 0; x--)
	{
		if (dig < 0)
		{
			result[j] = (dig / tens) * -1 + '0';
			j++;
		}
		else
		{
			result[j] = (dig / tens) + '0';
			j++;
		}
		dig %= tens;
		tens /= 10;
	}
	result[j] = '\0';
	return (result);
}
