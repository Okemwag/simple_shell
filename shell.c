#include "main.h"

/**
 * main - main function.
 *
 * Return: 0.
 */
int main(void)
{
	int condition = 1;
	int sign = 1;
	char *line = NULL;
	char **tokens = NULL;

	signal(SIGINT, sigint_handler);

	while (condition)
	{
		write(STDIN_FILENO, "$ ", 2);

		line = reading();
		sign = semicolon(line);
		tokens = cutting(line);
		condition = comparing(tokens);

		if (condition == 1 && sign == 1)
		{
			condition = executing(tokens, line);
		}
		free(line);
		free(tokens);
	}
	return (EXIT_SUCCESS);
}

/**
 * sigint_handler -  Signal Handler function.
 * @sigint: Reset handler to catch SIGINT next time.
 *
 * Return: Nothing.
 */
void sigint_handler(int sigint)
{
	(void)sigint;

	signal(SIGINT, sigint_handler);
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}
