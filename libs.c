#include "main.h"

int arg_count(char *str)
{
    char *buf, *tk;
    int x = 0; 
    int c;
    
    buf = NULL;
    tk = NULL;
    c = strlen(str);
    buf = malloc(c + 1);

    if (buf == NULL || str == NULL)
        perror("ERROR");

    buf = strcpy(buf, str);
    tk = strtok(buf, " \t\r\n\a");

    while (tk != NULL)
    {
        x++;
        tk = strtok(NULL, " \t\r\n\a");
    }
    free(buf);
    return (x);
}


