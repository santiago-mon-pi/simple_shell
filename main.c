#include "main.h"

int main(void)
{
    char *str = NULL;
    size_t line_size = 0;
    int in_c;
    int argc = 0;

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
                printf("%d\n", argc);

            }
        }
        free(str);
    return(0);
}
