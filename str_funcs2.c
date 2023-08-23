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

/**
 * dlm_ignore - It return the string without pre delimeters
 * @s: the sting
 * @d: the delimeter
 * Return: the new string
 */

char *dlm_ignore(char *s, char d)
{
	while (*s == d)
		s++;
	return (s);
}

/**
 * _strtok - it tokenizes the string and returns ann array
 * @s: the command
 * @d: the delimeter
 * Return: arrays of token
 */

char **_strtok(char *s, char *d)
{
	int buff_size = 0, ptr = 0, si = 0, i = 0, len = 0, se = 0, t = 0;
	char **tokens = NULL, ch;

	ch = d[0];
	s = dlm_ignore(s, ch);
	buff_size = f_size(s, ch);
	tokens = malloc(sizeof(char *) * (buff_size + 2));
	if (tokens == NULL)
		return (NULL);
	while (s[se] != '\0')
		se++;
	while (si < se)
	{
		if (s[si] != ch)
		{
			len = f_strlen(s, si, ch);
			token[ptr] = malloc(sizeof(char) * (len + 1));
			if (tokens[ptr] == NULL)
				return (NULL);
			i = 0;
			while ((s[si] != ch) && (s[si] != '\0'))
			{
				tokens[ptr][i] = s[si];
				i++;
				si++;
			}
			tokens[ptr][i] = '\0'
				t++;
		}
		if (si < se && (s[si + 1] != ch && s[si + 1] != '\0'
					ptr++;
					si++;
		}
		ptr++;
		tokens[ptr] = NULL;
		return (tokens);
}
