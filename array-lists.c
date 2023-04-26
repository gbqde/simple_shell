#include "shell.h"
/**
 * arr_size - Computes the size of a given
 * array of pointers to strings,
 * assuming that the array is terminated by a NULL pointer.
 *
 * @arr: Pointer to the array of pointers to strings.
 * Authors - owoyemi damilola and gbade moses
 * Return: The size of the array
 * (excluding the terminating NULL pointer).
 */
int arr_size(char **arr)
{
int i;
if (arr == NULL || *arr == NULL)
return (-1);
i = 0;
while (arr[i])
i++;
return (i);
}
/**
 * array_to_list - Constructs a linked
 * list of nodes from an input array of
 * pointers to strings. Each node contains a copy of a string
 * pointed to by one of the array elements. The function
 * returns a pointer to the head of the list, or NULL if an
 * error occurs.
 *
 * @array: Pointer to the array of pointers to strings.
 *
 * Return: Pointer to the head of the linked list, or NULL if an error occurs.
 */
list_t *array_to_list(char **array)
{
list_t *head;
list_t *new;
int i;
head = NULL;
for (i = 0; array[i] != NULL; i++)
{
new = add_node_end(&head, array[i]);
if (new == NULL)
{
free_list(head);
return (NULL);
}
}
return (head);
}
/**
 * list_to_array - Constructs an array of pointers
 * to strings from an input
 * linked list. The array contains copies of the strings stored
 * in each node of the list. The function returns a pointer to
 * the head of the array, or NULL if an error occurs.
 *
 * @head: Pointer to the head node of the linked list.
 *
 * Return: Pointer to the head of the array of pointers, or NULL if an error
 * occurs.
 */
char **list_to_array(list_t **head)
{
size_t len, i;
list_t *tmp;
char **array;
len = list_len(*head);
array = malloc(sizeof(char *) * (len + 1));
if (array == NULL)
return (NULL);
tmp = *head;
for (i = 0; i < len; i++)
{
array[i] = tmp->str;
tmp = tmp->next;
}
array[i] = NULL;
return (array);
}
/**
 * free_array - Deallocates the memory occupied by
 * a two-dimensional array of
 * pointers to strings. The function takes a pointer to the array
 * and frees all the memory allocated for its elements and the
 * array itself.
 *
 * @array: Pointer to the two-dimensional array of pointers to strings.
 *
 * Return: none
 */
void free_array(char **array)
{
int i, size;
size = arr_size(array);
if (*array == NULL || array == NULL)
return;
for (i = 0; i < size; i++)
{
if (array[i] != NULL)
free(array[i]);
}
free(array);
}
