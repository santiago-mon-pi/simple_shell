#include "head.h"

/**
 * interactive - execute shell in interctive mode
 *
 * Return: 0 to success.
 */
void *interactive(char *interactive_str, char *line)
{
    char **argument_variable = NULL;
    int len_characters = 0, argument_count = 0, bash_count = 1;
    size_t line_size = 0;

    while (EOF)
    {
        print_line(interactive_str);
        // clean standar input
        fflush(stdin);
        // Create len charecters and put data in &line
        len_characters = getline(&line, &line_size, stdin);

        // Validate line
        if (line == NULL)
            perror("Error");

        // Validate charecters
        if (len_characters == EOF)
        {
            free(line);
            fflush(stdin);
            exit(127);
        }
        // clean line, remove the last charecter ('\n')
        line = clean_line(line);

        // Get argc and validate if are parameters
        argument_count = argc(line);
        // Creating a argv, when this is created, free the line
        argument_variable = argv(line, argument_count);
        if (argument_count != 0)
        {
            argument_variable[0] = create_path_extension(argument_variable[0], argument_variable, argument_count);
            run_command(argument_variable, argument_count, bash_count);
        }
        else
        {
            free_double_pointer(argument_variable, argument_count);
        }
        bash_count++;
    }
    free(line);
}
