#include "shell.h"

/**
 * _strcmp - Compares two strings.
 *
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: The difference in value of the first character that's different.
 *
 * Authors: Owoyemi Damilola (DesignerRapheal) & Gbade Moses (gbqde)
 *
 */

int _strcmp(char *s1, char *s2)
{
	int i, dif;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			dif = s1[i] - s2[i];
			return (dif);
		}
		i++;
	}
	if (s1[i] == s2[i] && s1[i] == '\0')
		dif = 0;
	return (dif);
}

/**
 * _strchr - Locates a character in a string.
 *
 * @str: Pointer to the string.
 * @c: Character to find.
 *
 * Return: Pointer to the matched character or NULL.
 */

char *_strchr(char *str, char c)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
			return ((char *)(str + i));
	}
	return (NULL);
}

/**
 * len_to_char - Finds the length of a string up to a specified character.
 *
 * @str: Pointer to the string.
 * @c: Character to find.
 *
 * Return: The length of the string before the specified character,
 * or 0 if not found.
 */

int len_to_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	return (i);
}

/**
 * _atoi - Converts a string to an integer.
 *
 * @s: Pointer to the string to convert.
 *
 * Return: The converted number or -1 on error.
 */

int _atoi(char *s)
{
	int size, number, exponent, i;

	size = _strlen(s);
	exponent = 1;
	for (i = 1; i < size; i++)
		exponent *= 10;

	number = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			number += (s[i] - '0') * exponent;
		else
		{
			perror("Wrong input for exit status\n");
			return (-1);
		}
		exponent /= 10;
	}
	return (number);
}
