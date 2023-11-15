#include "main.h"

/**
 * _strcat - length of strings
 * Description: find digit
 * @src: char pointer
 * @dest: char pointer
 * Return: void
*/
char *_strcat(char *dest, char *src)
{
	strcat(dest, src);
	return (dest);
}

/**
 *  _strcpy - length of strings
 *  Description: find digit
 *  @src: int pointer
 *  @dest: int variable
 *  Return: char
*/
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}

/**
 * _strlen - calculates the length of a string
 * Description: lenght of string
 * @st : string
 * Return: length
*/
int _strlen(const char *st)
{
	int length = 0;

	while (st[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strcmp - compares two strings
 * Description: compare strings
 * @s1 : string 1
 * @s2 : string 2
 * Return: difference if strings are different and 0 if they are similar
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
			return (0);
	}
	return (s1[i] - s2[i]);
}
/**
 * _strdup - function to duplicate
 * @str: parameter
 * Return: allocated string
 */

char *_strdup(char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		ptr[i] = str[i];
	ptr[i] = 0;
	return (ptr);
}
