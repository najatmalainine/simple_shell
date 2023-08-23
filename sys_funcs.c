#include "shell.h"

/**
 * _which - finds command by appending it to a matching PATH directory
 * @s: the first command user typed
 * @envi: environmental variable
 * Return: a copy of the command
 */
char *_which(char *s, list_t *envi)
{
	char *path, *buf = NULL, **tokens;
	int i = 0;

	path = _getenv("PATH", envi);
	tokens = f_strtok(path, ":");
	free(path);

	i = 0;
	while (tokens[i] != NULL)
	{
		if (tokens[i][0] == '\0')
			buf = getcwd(buf, 0);
		else
			buf = _strdup(tokens[i]);
		buf = _strcat(buf, "/");
		buf = _strcat(buf, s);
		if (access(buf, F_OK) == 0)
		{
			free_db(tokens);
			return (buf);
		}
		free(buf);
		i++;
	}
	free_db(tokens);
	return (s);
}

/**
 * f_exit - it frees the user's command and linked list
 * @str: user's command
 * @envi: envirnment variable
 */
void f_exit(char **str, list_t *envi)
{
	free_db(str);
	free_linked_list(envi);
	_exit(0);
}

/**
 * _execve - execute user's command
 * @c: user's command
 * @envi: environmental variable
 * @n: the number of the current command being executed
 * Return: 0 on success
 */
int _execve(char **c, list_t *envi, int n)
{
	char *hol;
	int stat = 0, t = 0;
	pid_t pid;

	if (access(c[0], F_OK) == 0)
	{
		hol = c[0];
		t = 1;
	}
	else
		hol = _which(c[0], envi);
	if (access(hol, X_OK) != 0)
	{
		not_found(c[0], n, envi);
		free_db(c);
		return (127);
	}
	else /* If executable, fork and execute the command */
	{
		pid = fork();
		if (pid == 0) /* Child process */
		{
			if (execve(hol, c, NULL) == -1)
			{
				not_found(c[0], n, envi); /* Special error message */
				f_exit(c, envi);
			}
		}
		else /* Parent process */
		{
			wait(&stat); /* Wait for the child process to finish */
			free_db(c); /* Free the memory for command arguments */
			if (t == 0)
				free(hol); /* If the path was dynamically allocated, free it */
		}
	}
	return (0);
}

/**
 * _getline - stores the user's command into a buffer
 * @str: buffer
 * Return: number of read characters
 */
size_t _getline(char **str)
{
	char buf[1024];
	ssize_t i = 0, size = 0, a = 0, b = 0, num = 0;

	while (b == 0 && (i = read(STDIN_FILENO, buf, 1024 - 1)))
	{
		if (i == -1)
			return (-1);

		buf[i] = '\0';

		num = 0;
		while (buf[num] != '\0')
		{
			if (buf[num] == '\n')
				b = 1;
			num++;
		}


		if (a == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buf);
			size = i;
			a = 1;
		}
		else
		{
			size += i;
			*str = _strcat(*str, buf);
		}
	}
	return (size);
}

/**
 * _realloc - reallocate memory
 * @ptr: pointer to the previous memory allocated
 * @size_old: previous size
 * @size_new: new size
 * Return: pointer to reallocated memory
 */

void *_realloc(void *ptr, unsigned int size_old, unsigned int size_new)
{
	unsigned int j;
	void *q;

	if (size_new == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (size_new == size_old)
		return (ptr);

	if (ptr == NULL)
	{
		q = malloc(size_new);
		if (q == NULL)
			return (NULL);
		else
			return (q);
	}

	q = malloc(size_new);
	if (q == NULL)
		return (NULL);

	for (j = 0; j < size_old && j < size_new; j++)
		*((char *)q + j) = *((char *)ptr + j);
	free(ptr);

	return (q);
}
