#include "main.h"
/**
* print_env - print environnemnt variables
* Description: print env
* @env: char pointer
* Return: char
*/
void print_env(char **env)
{
	int j = 0;

	while (env[j])
	{
		write(STDOUT_FILENO, env[j], _strlen(env[j]));
		write(STDOUT_FILENO, "\n ", 1);
		j++;
	}
}

/**
* path - absolute path
* Description: paste all path
* @cmd: char pointer
* @pat: char pointer
* Return: char
*/

char *path(char *cmd, char *pat)
{
	char *folder = NULL, *absolute = NULL;
	struct stat statbuf;

	folder = strtok(pat, ":");
	while (folder != NULL)
	{
		absolute = malloc(_strlen(cmd) * _strlen(folder) + 2);
		if (absolute == NULL)
			exit(1);
		_strcpy(absolute, folder);
		_strcat(absolute, "/");
		_strcat(absolute, cmd);
		if (stat(absolute, &statbuf) == 0)
		{
			return (absolute);
		}
		free(absolute);
		folder = strtok(NULL, ":");
	}
	free(folder);
	return (cmd);
}

/**
* exec_cmd - execute command
* Description: execute command
* @cmd: char pointer
* @av: char pointer
* @arg: char pointer
* @error: char pointer
* Return: void
*/

int exec_cmd(char *cmd, char *av, char **arg, int error)
{
	pid_t child;
	int status = 0;
	int x = 0;

	child = fork();
	if (cmd != NULL)
	{
		if (child < 0)
		{
			perror(av);
			exit(1);
		}
		else if (child == 0)
		{
			if (execve(cmd, arg, NULL) == -1)
			{
				print(av, cmd, error);
				free_arr(arg);
				exit(1);
			}
		}
		else
			wait(&status);

		if (WIFEXITED(status))
		{
			x = WEXITSTATUS(status);
			return (x);
		}
	}
	return (0);
}
/**
* check_cmd - check command
* Description: check command
* @input: char pointer
* @av: char pointer
* @path_line: char pointer
* @error: char pointer
* Return: void
*/

int check_cmd(char **input, char *av, char *path_line, int error)
{
	char *command = NULL;
	int status;

		command = path(input[0], path_line);
		if (input[0] == command)
		{
			print(av, command, error);
			return (127);
		}
		else
			status = exec_cmd(command, av, input, error);

	free(command);
	return (status);
}
