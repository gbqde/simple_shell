#include "shell.h"


/**
* built_ins - checks if the given command is a built-in command
*
* @input: a pointer to a tokenized line from the command line
* @env_head: a pointer to the head of the
* linked list of environment variables
*
* This function takes in a pointer to
* tokenized line from the command line and
* a pointer to the head of the linked list of
* environment variables, and checks
* if the given command is a built-in command.
* If the command is a built-in, it
* executes the built-in command and returns 0 on success.
* If the command is not
* a built-in, it returns -1. If there is an error while executing
* the built-in
* command, it returns 1.
* Authors - owoyemi damilola and gbade moses
* Return: 0 on success, 1 on error, -1 if command is not a built-in
 */
int built_ins(char **input, list_t **env_head)
{
builtin_t builtins[] = {
{"exit", exit_bi}, {"env", print_env},
{"setenv", set_env}, {"unsetenv", unset_env},
{NULL, NULL}
};
int i, retval;
list_t *tmp;
tmp = *env_head;
if (!input)
{
perror("built_ins");
return (1);
}
i = 0;
while ((builtins + i)->bi != NULL)
{
if (_strcmp(input[0], (builtins + i)->bi) == 0)
{
if (_strcmp(input[0], END) == 0)
{
retval = (builtins + i)->f(input);
return (retval);
}
retval = (builtins + i)->f(input, &tmp);
return (retval);
}
i++;
}
return (-1);
}
/**
* exit_bi - Exits the shell with the given status.
*
* @line: A null-terminated array of pointers
* to tokens representing the command line.
* The last element of this array is expected to be a NULL pointer.
*
* This function frees any memory allocated
* by the shell and then terminates the process
* with the specified status. The status should be
* an integer in the range [0, 255].
*
* Return: This function does not return.
*/
int exit_bi(char **line)
{
int size, status;
size = arr_size(line);
if (size > 2)
{
_strprint("Failed: Command syntax: exit status\n");
return (1);
}
if (size == 1)
return (0);
if (size == 2)
{
status = _atoi(line[1]);
return (status);
}
return (1);
}
/**
* print_env - Prints the current environment variables.
*
* @line: Tokenized line from the command line.
* @env_head: Pointer to the head of the environment variable list.
*
* Return: 0 on success, 1 on error.
*/

int print_env(char **line, list_t **env_head)
{
int size;
list_t *tmp;
tmp = *env_head;
size = arr_size(line);
if (size > 1)
{
_strprint("Failed: Command syntax: env\n");
return (1);
}
print_list(tmp);
return (0);
}
/**
* set_env - Initializes a new environment
* variable or modifies an existing one.
*
* @line: Tokenized line from the command line.
* @env_head: Pointer to the head of the environment variable list.
*
* Return: 0 on success, 1 on error.
*/

int set_env(char **line, list_t **env_head)
{
int size;
int retval;
list_t *tmp;
tmp = *env_head;
size = arr_size(line);
if (size != 3)
{
_strprint("Failed: Command syntax: setenv VARIABLE VALUE\n");
return (1);
}
retval = _setenv(line[1], line[2], &tmp);
return (retval);
}
/**
* unset_env - Removes an environment variable from
* the list of environment
* variables. The function takes a tokenized line from the command
* line containing the name of the variable to be removed and a
* pointer to the head of the environment variable list. The
* function returns 0 on success and 1 on error.
*
* @line: Tokenized line from the command line.
* @env_head: Pointer to the head of the environment variable list.
*
* Return: 0 on success, 1 on error.
*/
int unset_env(char **line, list_t **env_head)
{
int size, retval;
list_t *tmp;
tmp = *env_head;
size = arr_size(line);
if (size != 2)
{
_strprint("Failed: Command syntax: unsetenv VARIABLE\n");
return (1);
}
retval = _unsetenv(line[1], &tmp);
return (retval);
}
