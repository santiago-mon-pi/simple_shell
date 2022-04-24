#include "main.h"
/**
 * print_line - double-use printer
 * @str: Input data array
 *
 **/

void print_line(char *str)
{
	int i, count;

	count = _strlen(str);
	for (i = 0; i < count; i++)
		write(1, &str[i], 1);
}
