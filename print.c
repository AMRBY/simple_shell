#include "main.h"
/**
 * print_number - prints an integer
 * @n: integer to be printed
 * Return: nothing
 */
void print_number(int n)
{
	unsigned int n1, n2;

	if (n < 0)
	{
		n1 = -n;
		write(STDERR_FILENO, "-", 1);
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);

	n2 = (n1 % 10) + 48;
	write(STDERR_FILENO, &n2, 1);

}

/**
* print - print char
* @input: pointer
* @cmd: pointer
* @error: int
* Description: print
* Return: void
*/

void print(char *input, char *cmd, int error)
{
	write(STDERR_FILENO, input, _strlen(input));
	write(STDERR_FILENO, ": ", 2);
	print_number(error);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
}

/**
 * free_arr - free an array
 * @arr: the array u wanna free
 * Return: nothing
*/
void free_arr(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/**
 * envr - get the env value py key
 * @path: the key
 * Return: value of the env
 */
char *envr(char *path)
{
	char *res, *line = NULL, *str;
	int i = 0;

	while (environ[i])
	{
		line = _strdup(environ[i]);
		str = _strdup(strtok(line, "="));
		if (_strcmp(str, path) == 0)
		{
			res = _strdup(strtok(NULL, "="));
			free(str);
			free(line);
			return (res);
		}
		free(str);
		free(line);
		i++;
	}
	return (NULL);
}
/**
 * slash - slash found
 * @str: command
 * Return: 1 or 0
 */
int slash(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
