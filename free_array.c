#include "main.h"
/**
 * free_array - cleans memory of double-pointer
 * @argv: double pointer to free
 * @argc: size of arguments
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
