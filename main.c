#include "main.h"

/**
 * main - execute new shell
 *
 * Return: 0 to success.
 */
int main(void)
{
    char *new_line = NULL;
    

    if (isatty(STDIN_FILENO) == 1)
    {
        // Interactive
        interactive("#interactive$ ", new_line);
    }
    else
    {
        // Non-interactive
        non_interactive(new_line);
    }


    return (0);
}
