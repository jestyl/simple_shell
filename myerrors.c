#include "shell.h"

/**
 *__eputs - Prints the specified input string.
 * @str: the string to be printed
 *
 * Return: No explicit return value.
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Writes a character 
 * @c: The character to be written.
 * Return: Returns 1 on success.
 */
int _eputchar(char c)
{
static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * _putfd - Writes a character to file descriptor.
 * @c: The character to be written.
 * @fd: The file descriptor to write to.
 * Return: Returns 1 on success.
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - Writes a string to file descriptor.
 * @str: The string to be written.
 * @fd: The file descriptor to write to.
 *
 * Return: Returns the number of characters written.
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
