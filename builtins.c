#include "main.h"

/**
 * _env - environment function.
 * @commands: General commands.
 *
 * Description: This function prints the environments variables.
 *
 * return: Nothing.
 */
void _env(char **commands)
{
	int i;
	char *s = *environ;

	if (commands[1] != NULL)
	{
		return;
	}

	for (i = 0; s; i++)
	{
		write(STDIN_FILENO, s, _strlen(s));
		write(STDIN_FILENO, "\n", 1);
		s = *(environ + i);
	}
}

/**
 * _cd - explore function.
 * @args: The number of arguments for cd.
 *
 * Description: This function change of directories in this Shell.
 *
 * Return: Always 2, to continue executing.
 */
int _cd(char **args)
{
	if (args[1] == NULL)
	{
		return (2);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			errors(args);
		}
	}
	return (2);
}
