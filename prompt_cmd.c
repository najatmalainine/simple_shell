#include "main.shell"

/**
 * prints_prompt - Repeatedly prints user typed command
 * @ev: Enviromental variables
 * Return: 0 for success
 */
int prints_prompt(char **ev)
{
	list_t *env;
	char *command, *n_command, **token;
	int command_line_no = 0, exit_stat = 0;
	size_t j = 0, n = 0;

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
		n = 0;
		while (command[n] != '\n')
			n++;
		command[n] '\0';
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
