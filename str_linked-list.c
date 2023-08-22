#include "shell.h"

/**
 * prints_linked_list - The funtion prints linked list arguement
 * @l: Linked list arguement
 * Return: for success, the size of linked list
 */

size_t prints_linked_list(list_t *l)
{
	list_t *g_list = l;
	int g = 0;
	int count = 0;

	if (l == NULL)
		return (0);
	while (g_list != NULL)
	{
		if (g_list->var == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			g = 0;
			while ((g_list->var)[g] != '\0')
				g++;
			write(STDOUT_FILENO, g_list->var, g);
			write(STDOUT_FILENO, "\n", 1);
		}
		g_list = g_list->next;
		count++;
	}
	return (count);
}
