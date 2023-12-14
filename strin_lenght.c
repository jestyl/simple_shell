#include "shell.h"

/**
 * _strlen - this will return the lenght of a string
 * @s: this helps to determine the string lenght to be checked
 *
 * Return: the integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string for comparison.
 * @s2: The second string for comparison.
 *
 * Return: Returns an integer less than, equal to, or greater than zero
 *         if s1 is found to be less than, equal to, or greater than s2, respectively.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * starts_with - Checks if a string starts with a specified prefix.
 * @haystack: The string to check.
 * @needle: The prefix to look for.
 * Return: Returns a pointer 
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to be appended.
 * Return: Returns a pointer to the concatenated string (dest).
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
