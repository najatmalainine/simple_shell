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

/**
 * free_linked_list - User typed in command to free linked list
 * @list: linked list variables
 */
void free_linked_list(list_t *list)
{
	list_t *hld;

	while (list != NULL)
	{
		hld = list;
		list = list->next;
		free(hld->var);
		free(hld);
	}
}

/**
 * node_index_rm - The function removes node int at index
 * @hd: Head address input
 * @index: Index input int
 * Return: For success 1, else -1
 */

int node_index_rm(list_t **hd, int index)
{
	int count = 0;
	list_t *no_hd;
	list_t *holder;

	if (*hd == NULL)
		return (-1);
	if (index == 0)
	{
		holder = (*hd)->next;
		free((*hd)->var);
		free(*hd);
		*hd = holder;
		return (1);
	}
	count = 1;
	no_hd = *hd;
	while (count < index)
	{
		if (no_hd == NULL)
			return (-1);
		no_hd = no_hd->next;
		count++;
	}
	holder = n_hd->next;
	no_hd->next = holder->next;
	free(holder->var);
	free(holder);
	return (1);
}

/**
 * add_end_node - Passing arguement to add node at linked list end
 * @hd: linked list head pointer
 * @s: string data to new node
 * Return: Pointer to the new linked list
 */

list_t *add_end_node(list_t **hd, char *s)
{
	list_t *nw;
	list_t *holder;

	if (hd == NULL || s == NULL)
		return (NULL);
	nw = malloc(sizeof(list_t));
	if (nw == NULL)
		return (NULL);

	nw->var = _strdup(s);
	nw->next = NULL;

	holder = *hd;
	if (holder != NULL)
	{
		while (holder->next != NULL)
		{
			holder = holder->next;
		}
		holder->next = nw;
	}
	else
	{
		*head = nw;
	}
	return (*head);
}
