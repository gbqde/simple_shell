#include "shell.h"

/**
 * list_len - This returns the number of elements in a linked list_t list.
 * @h: For linked list.
 *
 * Return: Number of elements.
 *
 * Authors: Owoyemi Damilola (DesignerRapheal) & Gbade Moses (gbqde)
 *
 */

size_t list_len(list_t *h)
{
	size_t len = 0;

	while (h != NULL)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: First node in the list.
 * @str: Second node in the list.
 *
 * Return: The address of the new element, or NULL if it failed.
 */

list_t *add_node(list_t **head, char *str)
{
	list_t *new_node;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	new_node->str = _strdup(str);
	if (!new_node->str)
		return (NULL);
	new_node->len = _strlen(str);
	new_node->next = *head;
	*head = new_node;

	return (*head);
}

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Pointer to first node in linked list.
 * @str: Data to be copied to string field of the node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */

list_t *add_node_end(list_t **head, char *str)
{
	list_t *new_node, *tail;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	new_node->str = _strdup(str);
	if (!new_node->str)
		return (NULL);
	new_node->len = _strlen(str);
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	tail = *head;
	while (tail->next)
		tail = tail->next;

	tail->next = new_node;

	return (new_node);
}

/**
 * free_list - Freeing the list_t list.
 * @head: Linked list to free.
 *
 * Return: None.
 */
void free_list(list_t *head)
{
	list_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current->str);
		free(current);
	}
}

/**
 * get_node - Returns the node with string str.
 * @head: Pointer to first node.
 * @str: String to search for.
 *
 * Return: N-th node. If the node does not exist, return NULL.
 */

list_t *get_node(list_t **head, char *str)
{
	list_t *current;

	if (!head)
		return (NULL);

	current = *head;
	while (current != NULL)
	{
		if (_strcmp(current->str, str) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
