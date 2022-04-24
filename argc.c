#include "main.h"

/**
 * argc - Count the strings in str
 * @str: the string with data
 *
 * Return: the numbers of strings separate with DELIM
 */

int argc(char *str)
{
	char *tokenizer = NULL, *copy_str = NULL;
	int len_str = 0;

	if (str == NULL)
		perror("Error");
	len_str = _strlen(str);
	copy_str = malloc(len_str + 1);
	if (copy_str == NULL)
		perror("Error");
	copy_str = _strcpy(copy_str, str);
	tokenizer = strtok(copy_str, DELIM);
	len_str = 0;
	while (tokenizer != NULL)
	{
		len_str++;
		tokenizer = strtok(NULL, DELIM);
	}
	free(copy_str);
	return (len_str);
}
