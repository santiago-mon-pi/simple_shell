#include "main.h"
/**
 * clean_line - free the line
 * @line: line to will free
 * Return: line
 */

char *clean_line(char *line)
{
	int len_line = 0;
	char *rturn_line = NULL;

	len_line = _strlen(line);
	rturn_line = (char *)malloc(sizeof(char) * len_line);
	if (rturn_line == NULL)
	{
		perror("Error");
	}
	rturn_line = _strcpy(rturn_line, line);
	rturn_line[len_line - 1] = '\0';
	return (rturn_line);

}
