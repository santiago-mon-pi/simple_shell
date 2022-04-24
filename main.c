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
       
        interactive("#interactive$ ", new_line);
    }
    else
    {
       
        non_interactive(new_line);
    }


    return (0);
}
