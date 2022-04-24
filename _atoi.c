#include "main.h"

/**
 * _atoi - Convert strintg to integer
 * @s: pointer to the string to be iterated
 *
 * Return: the number and sign of an array, 0 if no number.
 */
int _atoi(char *s)
{
	int i, sign = 0, num = 0, out = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
		{
			sign++;
		}
		if (s[i] >= 48 && s[i] <= 57)
		{
			num = num * 10 - (s[i] - '0');
			out = 1;
		}
		else if (out == 1)
		{
			break;
		}
	}
	if ((sign - 1) % 2 != 0)
	{
		num = num * -1;
	}
	return (num);
}
