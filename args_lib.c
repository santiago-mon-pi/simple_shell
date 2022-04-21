#include "main.h"
/**
 * arg_count - counts arguments in input
 * @str: pointer to save the input
 * Return: number of strings
 */
int arg_count(char *str)
{
	char *buf, *tk;
	int c, x = 0;

	buf = NULL;
	tk = NULL;
	c = _strlen(str);
	buf = malloc(c + 1);
	if (buf == NULL || str == NULL)
		perror("ERROR");
	buf = _strcpy(buf, str);
	tk = strtok(buf, " \t\r\n\a");
	while (tk != NULL)
	{
		x++;
		tk = strtok(NULL, " \t\r\n\a");
	}
	free(buf);
	return (x);
}
/**
 * **args_v - function for tokenizer
 * @str: pointer with a part of the imput
 * @argc: number of arguments in input
 * Return: an argument
 */
char **args_v(char *str, int argc)
{
	char *buffer = NULL, *token = NULL;
	char **arr;
	int i = 0, len_str = 0;

	arr = malloc(sizeof(char *) * (argc + 1));
	if (arr == NULL)
		perror("ERROR");
	if (str == NULL)
	{
		free(arr);
		perror("ERROR");
	}
	len_str = _strlen(str);
	buffer = malloc(sizeof(char) * (len_str + 1));
	if (buffer == NULL)
	{
		free(arr);
		perror("ERROR");
	}
	buffer = _strcpy(buffer, str);
	token = strtok(buffer, " \t\r\n\a");
	while (token != NULL)
	{
		len_str = _strlen(token);
		arr[i] = malloc(sizeof(char) * (len_str + 1));
		if (arr[i] == NULL)
		{
			free_array(arr, argc);
			perror("ERROR");
		}
		arr[i] = _strcpy(arr[i], token);
		token = strtok(NULL, " \t\r\n\a");
		i++;
	}
	arr[i] = NULL;
	free(buffer);
	free(str);
	return (arr);
}
