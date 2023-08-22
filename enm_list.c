#include "shell.h"

/**
 * enm_linked_list - Using enviromental var to create linked kist
 * @enm: enviromental variables
 * Return: linked list for success
 */

list_t *enm_linked_list(char **enm)
{
	list_t *hd;
	int j = 0;

	hd = NULL;
	while (enm[j] != NULL0)
	{
		add_end_node(&hd, enm[j]);
		j++;
	}
	return (hd);
}

/**
 * _enm - To prints enviromental varibles
 * @s: String command
 * @enm: Enviromental variables
 * Return: For success 0
 */

int _enm(char **s, list_t *enm)
{
	free_double_ptr(s);
	print_list(enm);
	return (0);
}

