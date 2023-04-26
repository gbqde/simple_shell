#include "shell.h"
/**
 * _getline - prints the shell prompt "$"
 * and read a line of input from the user
 * wait for the user to enter a command, prints it on
 * the next line excluding the terminating null style.
 * @input:A pointer to the buffer where to store input
 * @size: size of a buffer in bytes.
 * Return: chars read or -1 if _realloc failed
 * Authors - owoyemi damilola and gbade moses
 */
int _getline(char *input, int size)
{
int i;
int readval;
struct stat sb;
if (fstat(STDIN_FILENO, &sb) == -1)
{
perror("fstat");
exit(-1);
}
if ((sb.st_mode & S_IFMT) != S_IFIFO)
_strprint(PROMPT);
for (i = 0; i < size - 1; i++)
{
readval = read(STDIN_FILENO, (input + i), 1);
if (readval == 0)
return (-1);
 /* EOF */
if (input[i] == '\n')
break;
}
input[i] = '\0';
return (i);
}
/**
 * exit_shell - Check if the user input contains the
 * 'exit' command, which
 * terminates the shell. The function receives a tokenized input
 * line as argument, and returns 1 if the 'exit' command is present,
 *              or 0 otherwise.
 *
 * @line_tok: A pointer to the tokenized input line.
 *
 * Return: 1 if the 'exit' command is present, 0 otherwise.
 */

int exit_shell(char **line_tok)
{
int cmp, lend, lline, size;
size = arr_size(line_tok) < 3;
cmp = _strncmp(line_tok[0], END, _strlen(END));
lend = _strlen(END);
lline = _strlen(line_tok[0]);
if (cmp == 0 && lend == lline && size)
return (1);
return (0);
}
/**
 * clear_buffer - Sets all characters in the provided
 * buffer to 0. This function
 * is commonly used to reset the buffer before storing a new string.
 *
 * @buffer: Pointer to the buffer to reset.
 *
 * Return: None.
 */
void clear_buffer(char *buffer)
{
int i;
for (i = 0; i < BUFF_SIZE; i++)
buffer[i] = 0;
}
/**
 * mem_cpy-Copies the specified number of bytes
 * * from the source memory area
 * to the destination memory area. If the source and destination areas
 * overlap, the behavior is undefined. The function returns a pointer
 * to the destination memory area.
 *
 * @dest: Pointer to the memory area to copy to.
 * @src: Pointer to the memory area to copy from.
 * @n: Number of bytes to copy.
 *
 * Return: Pointer to the destination memory area.
 */

char *mem_cpy(char *dest, char *src, int n)
{
int i;
for (i = 0; i < n - 1; i++)
{
*(dest + i) = *(src + i);
}
*(dest + i) = '\0';
return (dest);
}
/**
 * _realloc - reallocates a memory block using malloc and free
* @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes of the new memory block
 *
 * Return: returns pointer to new memory location
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *array, *helper;
unsigned int i;
if (old_size == new_size)
return (ptr);
if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
if (ptr == NULL)
{
array = malloc(new_size);
if (array == NULL)
return (NULL);
return (array);
}
array = malloc(sizeof(char) * new_size);
if (array == NULL)
return (NULL);
if (new_size > old_size && old_size != 0)
{
helper = ptr;
for (i = 0; i < old_size; i++)
array[i] = helper[i];
free(ptr);
}
if (new_size < old_size)
{
helper = ptr;
for (i = 0; i < new_size; i++)
array[i] = helper[i];
free(ptr);
}
return (array);
}
