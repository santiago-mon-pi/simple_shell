#include "main.h"

/**
 * run_command - execute command and create new process threat to execute the command
 * @argv_command: arguments
 * @argc: count arguments
 * @bash_count: count bash execution line
 *
 * Return: path with the command
 */
void run_command(char **argv_command, int argc, int bash_count)
{
    int status = 0, i = 0;

    if ((_strcmp(argv_command[0], "exit") == 0) && (argc == 1))
    {
        fflush(stdin);
        free_double_pointer(argv_command, argc);
        exit(EXIT_SUCCESS);
    }

    if ((_strcmp(argv_command[0], "exit") == 0) && (argc == 2))
    {
        status = _atoi(argv_command[1]);
        fflush(stdin);
        free_double_pointer(argv_command, argc);
        exit(status);
    }

    if ((_strcmp(argv_command[0], "/usr/bin/env") == 0) && (argc == 1))
	{
		while (environ[i] != NULL)
		{
			_puts(environ[i]);
			_putchar(10);
			i++;
		}
	}

    create_process_to_execute(argv_command, argc, bash_count);
}

void create_process_to_execute(char **argv_command, int argc, int bash_count)
{
    pid_t process_id;

    process_id = fork();
    if (process_id == 0)
    {
        if (execve(argv_command[0], argv_command, NULL) == -1)
        {
            sys_error(argv_command, bash_count, "not found");
            bash_count--;
        }

        free_double_pointer(argv_command, argc);
        exit(0);
    }
    else
    {
        free_double_pointer(argv_command, argc);
        wait(NULL);
        kill(process_id, SIGKILL);
    }
}
