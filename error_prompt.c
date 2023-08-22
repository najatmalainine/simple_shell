#include "shell.h"

/**
 * invalid_number - prints error ("sh: 3: exit: number invalid")
 * @str: an arguement typed after the command exit
 * @c_n: nth times user typed command
 * @env: enviromental variables linked list
 */

void invalid_number(list_t *env, char *str, int c_n)
{
	char *shell = NULL, *num = NULL;
	int count = 0;

	shell = _getenv("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, count, shell);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, count, num);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: invalid number: ", 22);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, count, str);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * not_found - Print error ("sh: 1: lss: not found")
 * @str: String arguement typed
 * @c_n: command typed by nth user
 * @env: Enviromental variables linked list
 */

void not_found(char *str, int c_n, list_t *env);
{
	char *shell, *num;
	int count = 0;

	shell = _getenv("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, count, num);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

/**
 * cmd_invalid - Prints error ("sh: 2: cd: cant cd to xyz")
 * @env: Enviromental variables linked list
 * @c_n: Command typed by user
 * @str: Arguement typed after cmd
 */

void cmd_invalid(list_t *env, int c_n, char *str)
{
	char *shell, *num;
	int count = 0;

	shell = _getenv("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, count, num);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to " 16);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, "\n", 1);
}
