#include "main.h"

/**
 * reading - lecture function.
 *
 * Description: This function reads an entire line from stdin, storing
 * the text (including the newline and termination characters) in a buffer
 * and storing the address of the buffer in line.
 *
 * Return: The line read.
 */
char *reading(void)
{
	char *line = NULL;
	size_t buffsize = 0;
	ssize_t container = 0;

	container = getline(&line, &buffsize, stdin);

	if (container == -1)
	{
		free(line);
		exit(0);
	}
	return (line);
}

/**
 * cutting - Tokenize function.
 * @line: The pointer to the line that enters to tokenize.
 *
 * Description: This function breaks the chain into segments or
 * tokens depending on the delimiters that we impose on it, each time
 * it finds one it will tokenize it.
 *
 * Return: A pointer to the first token found in the string or null
 * if there are no tokens left to retrieve.
 */
char **cutting(char *line)
{
	char *slice;
	char **tokens;
	int position = 0;
	int buffer = 1024;

	tokens = malloc(buffer * sizeof(char *));

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	slice = strtok(line, " \t\n\r");
	while (slice)
	{
		tokens[position] = slice;
		position++;

		slice = strtok(NULL, " \t\n\r");
	}
	tokens[position] = NULL;
	return (tokens);
}
