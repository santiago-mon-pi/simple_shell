#include "main.h"
/**
 * argv - split a string and create an array of strings
 * @line: the string with data
 * @argument_count: counter of arguments in line
 * Return: the numbers of strings separate with DELIM
 */
char **argv(char *line, int argument_count)
{
	char **rturn_newline = NULL, *tmp_line = NULL, *tokenizer = NULL;
	int len_line = 0, i = 0;

	rturn_newline = malloc(sizeof(char *) * (argument_count + 1));
	if (rturn_newline == NULL)
	{
		perror("Error");
	}
	len_line = _strlen(line);
	tmp_line = malloc(sizeof(char) * (len_line + 1));
	if (tmp_line == NULL)
	{
		free(rturn_newline);
		perror("Error");
	}

	tmp_line = _strcpy(tmp_line, line);

	tokenizer = strtok(tmp_line, DELIM);
	len_line = 0;
	while (tokenizer != NULL)
	{
		len_line = _strlen(tokenizer);
		rturn_newline[i] = malloc(sizeof(char) * (len_line + 1));
		if (rturn_newline[i] == NULL)
		{
			free_double_pointer(rturn_newline, argument_count);
			perror("Error");
		}
		rturn_newline[i] = _strcpy(rturn_newline[i], tokenizer);
		tokenizer = strtok(NULL, DELIM);
		i++;
	}
	rturn_newline[i] = NULL;
	free(line);
	free(tmp_line);

	return (rturn_newline);
}


/**
 * free_double_pointer - free memory space
 * @argv: grid created. (array of pointers)
 * @argc: rows (integer)
 * Return: void.
 */
void free_double_pointer(char **argv, int argc)
{
	int i;

	i = 0;
	while (i < argc)
	{
		free(*(argv + i));
		i++;
	}
	free(argv);
}
