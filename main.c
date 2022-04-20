#include "main.h"

int main(void)
{
    char *str = NULL;
    size_t line_size = 0;
    int in_c;
    int argc = 0;
    char **argv;
    int cunt = 1;

    while (EOF)
        {
            puts("$hell");
            fflush(stdin);
            in_c = getline(&str, &line_size, stdin);

            if (in_c == EOF)
            {
                fflush(stdin);
                free(str);
                exit(127);
            }

            else
            {
                argc = arg_count(str);
                argv = args_v(str, argc);
                
                if (argc == 0)
                {
                    free_array(argv, argc);
                }
                else
                {
                    argv[0] = path_validator(argv[0], argv, argc, str);
                    _exec(argv, str, argc, cunt);
                }
                cunt++;
            }
        }
        free(str);
    return(0);
}
