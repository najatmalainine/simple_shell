#include "shell.h"
/**
 * main - The function creates simple shell
 * @agc: Arguement count
 * @agv: Arguement vector
 * @enm: Envorimental variables
 * Return: For success 0
 */
int main(int agc, char **agv, char **enm)
{
	(void)agc;
	(void)agv;

	prints_prompt(enm);
	return (0);
}
