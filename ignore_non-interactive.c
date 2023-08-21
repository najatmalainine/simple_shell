#include "shell.h"
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
	n_line = _str_tok(command, "\n");
	if (n_command != NULL)
		free(n_command);
	m = 0;
	while (n_line[m] != NULL)
	{
		command_line_no++;
		token = NULL;
		token = _str_tok(n_line[n], " ");
		exit_stat = built_in(env, token, command_line_no, n_line);
		if (exit_stat)
		{
			n++;
			continue;
		}
		exit_stat = _excve(env, token, command_line_no);
		m++;
	}
	free_double_ptr(n_line);
	free_linked_list(env);
	exit(exit_stat);
}

/**
 * free_double_ptr - free malloc arrays
 * @str: Array of string
 */
void free_double_ptr(char **str)
{
	int j = 0;

	while (str[j] != NULL)
	{
		free(str[j]);
		j++;
	}
	free(str);
}
