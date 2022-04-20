#include "main.h"

char *path_tk(char *path, char *tk)
{
    tk = strtok(path, "=");
    tk = strtok(NULL, "=");
    tk = strtok(tk, ":");

    return(tk);
}