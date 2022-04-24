#include "head.h"

/**
 * _puts - print a array charecters
 * @str: Input data array
 *
 **/

void _puts(char *str)
{
	int i, count;

	count = _strlen(str);
	for (i = 0; i < count; i++)
		_putchar(str[i]);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 **/

int _putchar(char c)
{
		return (write(1, &c, 1));
}
