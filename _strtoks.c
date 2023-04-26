#include "shell.h"
/**
 * count_words - Counts the number of
 * separate words in a given string, using
 * the specified delimiter to separate them. Words are defined
 * as consecutive non-delim characters. The function returns
 * the total number of words found in the string.
 *
 * @str:   Pointer to the string to analyze.
 * @delim: Character used as a delimiter.
 *
 * Return: The total number of words found in the string.
 */
int count_words(char *str, char delim);

int count_words(char *str, char delim)
{
int i, count;
i = 0;
count = 0;
while (str[i] != '\0')
{
if (str[i] != delim &&
(str[i + 1] == delim || str[i + 1] == '\t'
|| str[i + 1] == '\0'))
count++;
i++;
}
return (count);
}
/**
 * count_words - Counts the number of separate
 * words in a given string, using
 * the specified delimiter to separate them. Words are defined
 * as consecutive non-delim characters. The function returns
 * the total number of words found in the string.
 *
 * @str:   Pointer to the string to analyze.
 * @delim: Character used as a delimiter.
 *
 * Return: The total number of words found in the string.
 */
int count_words(char *str, char delim);

int _wrdlen(char *s, char delim)
{
int c = 0;
 /* count */
while (*(s + c) != delim && *(s + c) != '\0' && *(s + c) != '\t')
c++;
return (c);
}
/**
 * strtow - Splits a given string into separate words,
 * using the specified
 *  delimiter to identify word boundaries. Words are defined as
 *  consecutive non-delim characters. The function returns an array
 *  of strings, each containing one of the words found in the input
 * string. The returned array is terminated by a NULL pointer.
 *
 * @str:   Pointer to the string to split into words.
 * @delim: Character used as a delimiter.
 *
 * Return: Pointer to an array of strings (words)
 * or NULL if an error occurs.
 */
char **strtow(char *str, char delim)
{
int i, j, k, h, c, len;
char **words;
if (str == NULL || str[0] == '\0')
return (NULL);
c = count_words(str, delim);
if (c == 0)
return (NULL);
words = malloc(sizeof(char *) * (c + 1));
if (words == NULL)
return (NULL);
i = 0;
j = 0;
while (str[i] != '\0')
{
while ((str[i] == delim || str[i] == '\t') && str[i] != '\0')
i++;
if (str[i] == '\0')
{
words[j] = NULL;
return (words);
}
words[j] = malloc(sizeof(char) * (_wrdlen(str + i, delim) + 1));
if (words[j] == NULL)
{
for (k = j - 1; k >= 0; k--)
free(words[k]);
free(words);
return (NULL);
}
len = _wrdlen(str + i, delim);
for (h = 0; h < len && str[i] != '\0'; h++, i++)
words[j][h] = str[i];
words[j][h] = '\0';
j++;
}
words[j] = NULL;
return (words);
}
