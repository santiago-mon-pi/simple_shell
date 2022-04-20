#include "main.h"

char *path_acc(char *tk_buf, char *tk, char *cmd, char *path)

{
    tk_buf = _strcpy(tk_buf, tk);
    tk_buf = _strcat(tk_buf, "/");
    tk_buf = _strcat(tk_buf, cmd);
    
    if (access(tk_buf, X_OK) == 0)
    {
        free(path);
        free(cmd);
        return(tk_buf);
    }

    free(tk_buf);
    tk_buf = NULL;
    return(tk_buf);
}