#include "shell.h"

int own_env(char **args)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		print(environ[i], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}

void own_exit(char **tokenized_command)
{
	int num_token = 0, arg;

	for (; tokenized_command[num_token] != NULL; num_token++)
		;
	if (num_token == 1)
	{
		free(tokenized_command);
		free(line);
		free(commands);
		exit(0);
	}
	else if (num_token == 2)
	{
		arg = atoi(tokenized_command[1]);
		if (arg == -1)
		{
			printf(shell_name, STDERR_FILENO);
			printf(": 1: exit: Illegal number: ", STDERR_FILENO);
			printf(tokenized_command[1], STDERR_FILENO);
			printf("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(tokenized_command);
			free(commands);
			exit(arg);
		}
	}
	else
		printf("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
