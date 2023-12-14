#include "shell.h"

/**
 * _myenv - Displays the current environment.
 * @info: info structure
 *
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Retrieves the value of an environment variable .
 * @info: Pointer to the structure containing relevant information.
 * @name: The name of the environment variable to be retrieved.
 * Return: Returns a pointer to the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Set or update environment variable.
 * @info: Pointer to the structure containing relevant information.
 *
 * Return: Returns 1 on success, 0 on failure.
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - Remove specified environment variables.
 * @info: Pointer to the structure containing relevant information.
 *
 * Return: Returns 0 on success, 1 on failure.
 */

int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - Populate linked list with environment variables.
 * @info: Pointer to the structure containing relevant information.
 *
 * Return: Always returns 0.
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
