#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 *
 * @s: Pointer to the string.
 *
 * This function calculates the length of the string pointed to by @s.
 * The length of a string is the number of characters preceding the
 * terminating null byte ('\0').
 *
 * Return: Length of @s on success.
 */


int _strlen(char *s)
{
	int count = 0;

	if (s != NULL)
	{
		while (*(s + count) != '\0')
			count++;
	}
	return (count);
}

/**
 * _strncmp - Compares two strings for a specified number of characters.
 *
 * @s1: Pointer to the first string to be compared.
 * @s2: Pointer to the second string to be compared.
 * @n: Number of characters to compare.
 *
 * Return: 0 if the two strings are identical for the first n characters
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i, dif;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return (-1);
		if (s1[i] != s2[i])
		{
			dif = s1[i] - s2[i];
			return (dif);
		}
		i++;
	}
	return (0);
}

/**
 * _strcpy - Copies the string with null terminator to the buffer
 *
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source string
 *
 * Return: Pointer to the destination buffer
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * _strcat - Appends the `src` string to the `dest` string.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 *
 * Return: Pointer to the resulting string `dest`.
 */

char *_strcat(char *dest, char *src)
{
	int i, length;

	length = _strlen(dest);
	for (i = 0; src[i] != '\0'; i++)
		dest[length + i] = src[i];
	dest[length + i] = '\0';
	return (dest);
}

/**
 * _strdup - Returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter.
 *
 * @str: String to copy.
 *
 * Return: Pointer to new string or NULL if str = NULL.
 */

char *_strdup(char *str)
{
	int i, len;
	char *new_str;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		new_str[i] = str[i];
	new_str[len] = '\0';
	return (new_str);
}
