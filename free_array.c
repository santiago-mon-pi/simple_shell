#include "main.h"
/**
 * free_array - function to free up space meory
 * @argv: space memory to free
 * @argc: size of argument inside
 */
void free_array(char **argv, int argc)
{
	int i = 0;

	while (i < argc)
	{
		free(*(argv + i));
		i++;
	}
	free(argv);
}
