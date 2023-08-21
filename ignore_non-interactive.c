#include "shell.h"

/**
 * ignore_c - ignoring spaces and new lines
 * @str: enviromantal varaibles
 * Return: new string
 */

char *ignore_c(char *str)
{
	while (*str == ' ' || *str == '\n')
		str++;
	return (str);
}

/**
 * free_db - free malloced arrays
 * @str: array of strings
 */
void free_db(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/**
 * non_interactive - when user pipes in command into shell via pipeline
 * @env: Enviromental variable
 */

void non_interactive(list_t *env)
{
	int command_line_no = 0, exit_stat;
	char *command = NULL, *n_command = NULL, **n_line, **token;
	size_t j = 0, m = 0;

	j = get_line(&command);
	if (j == 0)
	{
		free(command);
		exit(0);
	}
	n_command = command;
	command = c_ignore(command);
	n_line = _strtok(command, "\n");
	if (n_command != NULL)
		free(n_command);
	m = 0;
	while (n_line[m] != NULL)
	{
		command_line_no++;
		token = NULL;
		token = _strtok(n_line[n], " ");
		exit_stat = built_in(env, token, command_line_no, n_line);
		if (exit_stat)
		{
			m++;
			continue;
		}
		exit_stat = _execve(env, token, command_line_no);
		m++;
	}
	free_db(n_line);
	free_linked_list(env);
	exit(exit_stat);
}
