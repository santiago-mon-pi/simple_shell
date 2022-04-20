#include "main.h"

char *path_validator(char *cmd, char **argv, int argc, char *tmp)

{
    int env_len = 0, tk_len = 0, i;
    char *path_buf;
    char *tk = NULL;
    char *tmp_tk;
    

    if (cmd[0] != '/')
    {
        for (i = 0; environ[i] != NULL; i++)
        {
            if (_strcmp(environ[i], "PATH") == 0)
            {
                env_len = _strlen(environ[i]);
                path_buf = malloc(sizeof(char) * (env_len + 1));

                if (path_buf == NULL)
                {
                    free_array(argv, argc);
                    free(tmp);
                    perror("ERROR");
                }

                path_buf = _strcpy(path_buf, environ[i]);
            }
        }
        tk = path_tk(path_buf, tk);

        while (tk != NULL)
        {
            tk_len = _strlen(tk);
            tmp_tk = malloc(sizeof(char)* (tk_len + _strlen(cmd)+ 2));

            if (tmp_tk == NULL)
            {
                free_array(argv, argc);
                free(tmp);
                free(path_buf);
                perror("ERROR");
            }

            tmp_tk = path_acc(tmp_tk, tk, cmd, path_buf);

            if (tmp_tk != NULL)
            {
                return(tmp_tk);
            }
            
            tmp_tk = strtok(NULL, ";");
        }
        free(path_buf);
        return(cmd);
    }
    return(cmd);
}