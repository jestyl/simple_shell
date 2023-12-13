#include "shell.h"

/**
 **_memset - Populates a memory area pointed by s with a specified constant byte.
 *@s: Pointer to the memory area.
 *@b: The byte used to fill the memory.
 *@n: The number of bytes to be filled.
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
/*
 * Function: ffree
 * ----------------
 * Description: This function is responsible for freeing up memory allocated
 *              using a custom memory management scheme 
 *
 * Parameters:
 *   - memory_block: A pointer to the memory block that needs to be freed.
 *
 * Returns: void
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
/*
 * _realloc: Resizes a dynamically allocated memory block.
 * Parameters: ptr - Pointer to the memory block.
 * Returns: New pointer on success, NULL on failure or if new_size is zero.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
