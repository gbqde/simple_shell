#include "shell.h"

/**
 * pathDirsArray - makes array of pointers for all dirs in the PATH
 * @envHead: pointer to environ list
 *
 * Return: Array of pointers
 *
 * Authors: Owoyemi Damilola (DesignerRapheal) & Gbade Moses (gbqde)
 *
 */

char **pathDirsArray(list_t **envHead)
{
	char *ptr;
	char *name = "PATH";
	char *pathStr;
	char delim = ':';
	char **dirs;
	list_t *tmp;

	tmp = *envHead;

	/* get string PATH=... from environment */
	ptr = _getenv(name, &tmp);

	/* duplicate string starting at char after = */
	pathStr = _strdup(ptr + 5);

	/* tokenize into separate string dirs */
	dirs = strtow(pathStr, delim);

	if (dirs == NULL)
	{
		free(pathStr);
		return (NULL);
	}

	free(pathStr);
	return (dirs);
}

/**
 * cmdInPath - finds command in the PATH
 * @str: pointer to first string in input line (command)
 * @envHead: pointer to environ list
 *
 * Description: steps
 * 1. tokenize path directories
 * 2. check if str in path and then concat command to PATH directories
 * 3. use access sys_call to see if it's binary executable
 * 4. realloc memory for cmd +2 = +1 for '/' +1 for '\0'
 *
 * Return: pointer to absolute path of command or NULL if not found
 */
char *cmdInPath(char *str, list_t **envHead)
{
	char **pathDirs, *cmd;
	int i, j, cmdl, strl;
	list_t *tmp;

	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] == '/' && str[j + 1] != '\0' &&
			str[j + 1] != '/' && access(str, F_OK | X_OK) == 0)
			return (str);
	}

	if ((str[0] == '/' || str[0] == '.') && str[j] == '\0')
	{
		_strprint(str);
		_strprint(": not found\n");
		return (NULL);
	}

	tmp = *envHead;
	pathDirs = pathDirsArray(&tmp);

	if (pathDirs == NULL)
	{
		perror(ENOMEM);
		return (NULL);
	}

	for (i = 0; pathDirs[i] != NULL; i++)
	{
		cmd = _strdup(pathDirs[i]);
		cmdl = _strlen(cmd);
		strl = _strlen(str);
		cmd = _realloc(cmd, cmdl, cmdl + strl + 2);
		cmd = _strcpy(cmd, pathDirs[i]);
		cmd = _strcat(cmd, "/");
		cmd = _strcat(cmd, str);

		if (access(cmd, F_OK) == 0)

		{
			free_array(pathDirs);
			return (cmd);
		}
	}

	free_array(pathDirs);
	return (str);
}

/**
 * runCommand - runs the command typed into shell prompt
 * @lineTok: tokenized input line
 * @envHead: pointer to environ list
 * Return: Always 0 on success, 1 on error
 */
int runCommand(char **lineTok, list_t **envHead)
{
	pid_t childPid;
	int status;
	char **envArray;
	char *command;
	list_t *tmp;

	tmp = *envHead;
	envArray = listToArray(&tmp);

	if (envArray == NULL)
	{
		perror(ENOMEM);
		return (1);
	}

	childPid = fork();

	if (childPid == -1)
	{
		perror("runCommand: child pid is -1");
		free(envArray);
		return (1);
	}

	if (childPid == 0)
	{
		/* find command (first token) in the PATH */
		command = cmdInPath(lineTok[0], &tmp);
		if (command == NULL)
			exit(1);

		/* run execve (abs path, rest of the tokens, env) */
		if (execve(command, lineTok, envArray) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}

	free(envArray);
	return (0);
}
