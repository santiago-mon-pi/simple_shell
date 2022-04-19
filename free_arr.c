#include "main.h"



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