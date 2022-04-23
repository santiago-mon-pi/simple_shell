#include "main.h"

void _exec(char **argv, char *buf, int argc, int count)
{
	int i = 0, stat = 0;

	if ((_strcmp(argv[0], "exit") == 0) && (argc == 1))
	{
		fflush(stdin);
		free_array(argv, argc);
		free(buf);
		exit(EXIT_SUCCESS);
	}
	if ((_strcmp(argv[0], "exit") == 0) && (argc == 2))
	{
			stat = _atoi(argv[1]);
			fflush(stdin);
			free_grid(argv, argc);
			free(buf);
			exit(stat);
	}

	if ((_strcmp(argv[0], "/usr/bin/env") == 0) && (argc == 1))
	{
		while (environ[i] != NULL)
		{
			_puts(environ[i]);
			_putchar(10);
			i++;
		}
	}
	else
		fork_process(argv, buf, argc, count);
}
