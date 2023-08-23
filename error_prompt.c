#include "shell.h"

/**
 * invalid_number - prints error
 * @s: an arguement typed after the command exit
 * @c_no: nth times user typed command
 * @enm: enviromental variables linked list
 */

void invalid_number(char *s, int c_no, list_t *enm)
{
	char *shell = NULL, *n = NULL;
	int count = 0;

	shell = _getenv("_", enm);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	n = int_to_string(c_no);
	count = 0;
	while (n[count] != '\0')
		count++;
	write(STDOUT_FILENO, n, count);
	free(n);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: invalid number: ", 22);
	count = 0;
	while (s[count] != '\0')
		count++;
	write(STDOUT_FILENO, s, count);
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * not_found - Print error
 * @s: String arguement typed
 * @c_no: command typed by nth user
 * @enm: Enviromental variables linked list
 */

void not_found(char *s, int c_no, list_t *enm)
{
	char *shell, *n;
	int count = 0;

	shell = _getenv("_", enm);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	n = int_to_string(c_no);
	count = 0;
	while (n[count] != '\0')
		count++;
	write(STDOUT_FILENO, n, count);
	free(n);
	write(STDOUT_FILENO, ": ", 2);
	count = 0;
	while (s[count] != '\0')
		count++;
	write(STDOUT_FILENO, s, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

/**
 * cmd_invalid - Prints error
 * @enm: Enviromental variables linked list
 * @c_no: Command typed by user
 * @s: Arguement typed after cmd
 */

void cmd_invalid(char *s, int c_no, list_t *enm)
{
	char *shell, *n;
	int count = 0;

	shell = _getenv("_", enm);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	n = int_to_string(c_no);
	count = 0;
	while (n[count] != '\0')
		count++;
	write(STDOUT_FILENO, n, count);
	free(n);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	count = 0;
	while (s[count] != '\0')
		count++;
	write(STDOUT_FILENO, s, count);
	write(STDOUT_FILENO, "\n", 1);
}
