#include "shell.h"

/**
 * _putchar - This writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 *
 * Authors: Owoyemi Damilola (DesignerRapheal) & Gbade Moses (gbqde)
 *
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _strprint - prints a string
 * @str: pointer to string to print
 *
 * Return: none
 */

void _strprint(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * print_array - Prints an array of strings
 * @array: The array to print
 *
 * Return: nothing
 */

void print_array(char **array)
{
	int i;

	if (!array || !(*array))
	{
		perror(WRONG);
		return;
	}

	for (i = 0; array[i] != NULL; ++i)
	{
		_strprint(array[i]);
		_putchar('\n');
	}
}

/**
 * print_list - This prints all the elements of a list_t list
 * @h: The linked list
 *
 * Return: Number of elements
 */

size_t print_list(list_t *h)
{
	size_t len = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		_strprint(h->str);
		_putchar('\n');
		h = h->next;
		len++;
	}

	return (len);
}

