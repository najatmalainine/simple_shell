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

	shell = get_env("_", env);
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
