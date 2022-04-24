#include "head.h"

/**
 * _strcmp - print te charecter ++ or --
 * @s1: input char # 1
 * @s2: input char # 2
 *
 * Return: integer
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; (s1[i] != '\0') && (s2[i] != '\0'); i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
