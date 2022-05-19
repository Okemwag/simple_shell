#include "main.h"

/**
 * comparing - compare function.
 * @tokens: The tokenized line.
 *
 * Description: This function compare the built-in with the command entered.
 *
 * Return: The built-in function result.
 */
int comparing(char **tokens)
{
	if (tokens[0] == NULL)
	{
		return (1);
	}

	if (_strcmp(tokens[0], "exit") == 0)
	{
		return (0);
	}
	if (_strcmp(tokens[0], "env") == 0)
	{
		_env(tokens);
	}
	if (_strcmp(tokens[0], "cd") == 0)
	{
		return (_cd(tokens));
	}
	return (1);
}


/**
 * executing - execute function.
 * @tokens: The tokenized line.
 * @line: bla bla
 *
 * Return: 1.
 */
int executing(char **tokens, char *line)
{
	pid_t pid;
	int o, status;
	char path[8192] = "/bin", *aux = "/b", *aux2 = " /b.h";

	if (line[0] == aux[0] && line[1] == aux[1])
		_strcpy(path, line);
	else if (line[0] == aux2[0])
	{
		for (o = 0; line[o] != '\0'; o++)
		{
			if (line[o] == aux2[1])
				if (line[o - 1] == aux2[0])
					_strcpy(path, "/bin/ls");
		}
	}
	else if (line[0] == aux2[3] && line[2] == aux2[4])
		_strcpy(path, "/bin/ls");
	else
		_strcat(path, "/"), _strcat(path, line);
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, tokens, environ) == -1)
		{
			errors(tokens);
			return (0); }
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		errors(tokens);
		return (0);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
