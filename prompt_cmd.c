#include "shell.h"

/**
 * ctrl_d - if ctrl-d was typed exit program
 * @c: the characters that _getline reads
 * @cmd: the user's command
 * @enm: environment variable
 */
void ctrl_d(int c, char *cmd, list_t *enm)
{
	if (c == 0)
	{
		free(cmd);
		free_linked_list(enm);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * _ctrl_c - Prints prompts by ignoring ctrl-C command
 * @num: Inputs signal
 */
void _ctrl_c(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n$ ", 3);
}


/**
 * takein_space - it returns the string without
 * @s: string
 * Return: string
 */
char *takein_space(char *s)
{
	while (*s == ' ')
		s++;
	return (s);
}

/**
 * _builtin - builtin functions
 * @tkn: the typed in command
 * @envi: the environmental variable
 * @n: the nth user command typed for errors
 * @cmd: the command to free
 * Return: 1 if acted on builtin, 0 if not
 */
int _builtin(char **tkn, list_t *envi, int n, char **cmd)
{
	int i = 0;

	if (_strcmp(tkn[0], "exit") == 0)
	{
		i = ___exit(tkn, envi, n, cmd);
	}
	else if (_strcmp(tkn[0], "env") == 0)
	{
		_env(tkn, envi);
		i = 1;
	}
	else if (_strcmp(tkn[0], "cd") == 0)
	{
		i = _cd(tkn, envi, n);
	}
	else if (_strcmp(tkn[0], "setenv") == 0)
	{
		_setenv(&envi, tkn);
		i = 1;
	}
	else if (_strcmp(tkn[0], "unsetenv") == 0)
	{
		_unsetenv(&envi, tkn);
		i = 1;
	}
	return (i);
}


/**
 * prints_prompt - prints user typed command
 * @ev: envrionmental variables
 * Return: 0 on success
 */
int prints_prompt(char **ev)
{
	list_t *envi;
	size_t j = 0, num = 0;
	int cmd_no = 0, ex_status = 0;
	char *cmd, *n_cmd, **tkn;

	envi = env_linked_list(ev);
	do {
		cmd_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(envi);
		signal(SIGINT, _ctrl_c);
		cmd = NULL;
		j = 0;
		j = _getline(&cmd);
		ctrl_d(j, cmd, envi);
		n_cmd = cmd;
		cmd = takein_space(cmd);
		num = 0;
		while (cmd[num] != '\n')
			num++;
		cmd[num] = '\0';
		if (cmd[0] == '\0')
		{
			free(n_cmd);
			continue;
		}
		tkn = NULL;
		tkn = _strtok(cmd, " ");
		if (n_cmd != NULL)
			free(n_cmd);
		ex_status = _builtin(tkn, envi, cmd_no, NULL);
		if (ex_status)
			continue;
		ex_status = _execve(tkn, envi, cmd_no);
	} while (1);
	return (ex_status);
}
