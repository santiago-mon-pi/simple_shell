#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 * @str: runs through the string
 *
 **/

void _puts(char *str)
{
	int i;

	for  (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
/**
 * _atoi - convert str to int
 * @s: str to be processed
 * Return: integer
 */
int _atoi(char *c)
{
	int len_str = _strlen(c);
	int i = 0;
	int sign = 0;
	int res = 0;

	while (i <= len_str)
	{
		if (c[i] == '-')
			sign++;
		if (c[i] >= '0' && c[i] <= '9')
		{
			if (sign % 2)
				res = (res * 10) - (c[i] - '0');
			else
				res = (res * 10) + (c[i] - '0');
			if (c[i + 1] < '0' || c[i + 1] > '9')
				break;
		}
		i++;
	}
	return (res);
}
/**
 * system_error - displays error in command line
 * @argv: pointer to pointer
 * @count: counter
 * @error: exit error.
 **/

void system_error(char **argv, int count, char *error)
{
	_puts("$shell: ");
	print_num(count);
	_puts(": ");
	_puts(argv[0]);
	_puts(": ");
	_puts(error);
	_putchar(10);
}

void print_num(int n)
{
	unsigned int mid;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	mid = n;
	if (mid / 10)
	{
		print_num(mid / 10);
	}
	_putchar(mid % 10 + '0');
}