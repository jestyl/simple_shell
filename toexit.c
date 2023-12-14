#include "shell.h"

/**
 **_strncpy - Copies a specified number of characters from the source string to the destination string.
 *@dest: the destination string will be copied
 *@src: this is the source string
 *@n: this is the number of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - Concatenates n characters 
 * @dest: The destination string.
 * @src: The source string to be appended.
 * @n: The maximum number of characters to append.
 * Return: Returns a pointer to the concatenated string (dest).
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}
/**
 * _strchr - Locates occurrence of a character 
 * @s: The string to search.
 * @c: The character to locate.
 *
 * Return: Returns a pointer 
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
