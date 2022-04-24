#include "head.h"

/**
 * non_interactive - if insert code in mode interactive execute
 * @buf: buf to getline
 * @argv: the new argv
 * @buf_size: new size of getline
 **/

void non_interactive(char *line)
{
	int argument_count = 0, bash_count = 1;
	char **argument_variable = NULL;
    size_t line_size = 0;

	while (getline(&line, &line_size, stdin) != EOF)
	{

        if (line == NULL)
            perror("Error");
            
		line = clean_line(line);
		argument_count = argc(line);
		argument_variable = argv(line, argument_count);

		if (argument_count != 0)
		{
			argument_variable[0] = create_path_extension(argument_variable[0], argument_variable, argument_count);
			run_command(argument_variable, argument_count, bash_count);
		}
		else
			free_double_pointer(argument_variable, argument_count);
	}
	free(line);
	exit(0);
}
