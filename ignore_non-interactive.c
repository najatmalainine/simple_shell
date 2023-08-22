#include "shell.h"

/**
 * ignore_c - ignoring spaces and new lines
 * @s: enviromantal varaibles
 * Return: new string
 */

char *ignore_c(char *s)
{
	while (*s == ' ' || *s == '\n')
		s++;
	return (s);
}

/**
 * free_db - free malloced arrays
 * @s: array of strings
 */
void free_db(char **s)
{
	int j = 0;

	while (s[j] != NULL)
	{
		free(s[j]);
		j++;
	}
	free(s);
}

/**
 * non_interactive - when user pipes in command into shell via pipeline
 * @enm: Enviromental variable
 */

void non_interactive(list_t *enm)
{
	int cmd_line_no = 0, ex_status;
	char *cmd = NULL, *cmd_no = NULL, **n_line, **tkn;
	size_t j = 0, m = 0;

	j = _getline(&cmd);
	if (j == 0)
	{
		free(cmd);
		exit(0);
	}
	cmd_no = cmd;
	cmd = c_ignore(cmd);
	n_line = _strtok(cmd, "\n");
	if (cmd_no != NULL)
		free(cmd_no);
	m = 0;
	while (n_line[m] != NULL)
	{
		cmd_line_no++;
		tkn = NULL;
		tkn = _strtok(n_line[m], " ");
		ex_status = _builtin(tkn, enm, cmd_line_no, n_line);
		if (ex_status)
		{
			m++;
			continue;
		}
		ex_status = _execve(tkn, enm, cmd_line_no);
		m++;
	}
	free_db(n_line);
	free_linked_list(enm);
	exit(ex_status);
}
