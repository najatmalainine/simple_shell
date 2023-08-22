#include "main.shell"

/**
 * prints_prompt - Repeatedly prints user typed command
 * @ev: Typed in Enviromental variables
 * Return: 0 for success
 */
int prints_prompt(char **ev)
{
	list_t *env;
	char *command, *n_command, **token;
	int command_line_no = 0, exit_stat = 0;
	size_t j = 0, m = 0;

	env = env_linked_list(ev);
	do {
		command_line_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILE, "$ ", 2);
		else
			non_interavctive(env);
		signal(SIGNAL, ctrl_c);
		command = NULL, j = 0;
		j = get_line(&command);
		ctrl_D(j, command, env);
		n_command = command;
		command = ignore_space(command);
		m = 0;
		while (command[m] != '\n')
			m++;
		command[m] '\0';
		if (command[0] == '\0')
		{
			free(n_command);
			continue;
		}
		token = NULL, token = _str_tok(command, " ");
		if (n_command != NULL)
			free(n_command);
		exit_stat = built_in(token, command_line_no, env, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execve(env, token, command_line_no);
	} while (1);
	return (exit_stat);
}

/**
 * ctrl_c - Prints prompts by ignoring ctrl-C command
 * @m: Inputs signal
 */
void ctrl_c(int m)
{
	(void)m;

	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * handles_builtin - builtin functions are taken care of (exit, env, cd)
 * @command: As user typed, brings command to free
 * @token: typed in  command
 * @env: typed in Enviromental variables
 * @num: Write error message after taking in command
 * Return: 1 for success, else 0
 */

int handles_builtin(char **token, int num, char **command, list_t *env)
{
	int j = 0;

	if (_strcmp(token[0], "exit") == 0)
	{
		j = _exit(token, command, num, env);
	}
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
		j = 1;
	}
	else if (_strcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		j = 1;
	}
	else if (_strcmp(token[0], "cd") == 0)
	{
		j = _cd(token, num, env);
	}
	else if (_strcmp(token[0], "env") == 0)
	{
		_env(env, token);
		j = 1;
	}
	return (1);
}

