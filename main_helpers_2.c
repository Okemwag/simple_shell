#include "main.h"

/**
 * semicolon -  This function handle the commands separator ";"
 * @line: The pointer to the stdin line entered.
 *
 * Return: 0.
 */
int semicolon(char *line)
{
	char *one_token, **total, **tokens;
	int buffer = 1024, status = 1, i = 0, j = 0;

	total = malloc(buffer * sizeof(char *));

	if (!total)
	{
		exit(EXIT_FAILURE);
	}
	one_token = strtok(line, ";");
	while (one_token)
	{
		total[i] = one_token;
		i++;
		one_token = strtok(NULL, ";");
	}
	total[i] = NULL;
	if (total[1] == NULL)
	{
		free(total);
		return (1);
	}
	else
	{
		while (total[j])
		{
			tokens = cutting(total[j]);
			status = comparing(tokens);

			if (status == 1)
			{
				status = executing(tokens, line);
			}
			j++;
			free(tokens);
		}
	}
	free(total);
	return (0);
}
