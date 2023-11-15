#include "main.h"

/**
* tokenn - split all the command
* @str: the command we get
* Return: an array of the splited command
*/
char **tokenn(char *str)
{
	char *token, **tokens;
	int i = 0;

	tokens = malloc(1025 * sizeof(char *));
	if (tokens == NULL)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
	token = strtok(str, " \t\n");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
* get - read the command form stdin and split it
* @status: status code
* @args: command holder
* Return: -1 or 0
*/
int get(int status, char ***args)
{
	char *buf = NULL;
	size_t size_buf = 0;
	int i;

	i = getline(&buf, &size_buf, stdin);
	if (i == -1)
	{
		free(buf);
		exit(status);
	}
	buf[i - 1] = '\0';
	*args = tokenn(buf);
	free(buf);
	if (*args == NULL || *args[0] == NULL)
	{
		free(*args);
		return (-1);
	}
	return (0);
}

/**
* main - main function
* Description: prompt
* @ac: int
* @av: char pointer
* @env: char pointer
* Return: int
*/

int main(int __attribute__((unused)) ac, char **av, char **env)
{
	int status = 0, error = 0;
	char **args = NULL, *path_line = NULL;
	struct stat statbuff;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		error++;
		if (get(status, &args) == -1)
			continue;

		if (_strcmp(args[0], "exit") == 0)
		{
			free_arr(args);
			exit(status);
		}
		else if (_strcmp(args[0], "env") == 0)
		{
			print_env(env);
			free_arr(args);
			continue;
		}
		else if (slash(args[0]) == 1)
		{
			if (stat(args[0], &statbuff) != 0)
				print(av[0], args[0], error);
			else
				status = exec_cmd(args[0], av[0], args, error);

			free_arr(args);
			continue;
		}

		path_line = envr("PATH1");
		status = check_cmd(args, av[0], path_line, error);
		free_arr(args);
		free(path_line);
	}
	return (0);
}

