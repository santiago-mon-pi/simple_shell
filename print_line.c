#include "main.h"
/**
 * _puts - print a array charecters
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

