#include "main.h"

void fork_process(char **argv, char *buf, int argc, int count)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			system_error(argv, count, "not found");
			count--;
		}

		free_array(argv, argc);
		free(buf);
		exit(0);
	}
	else
	{
		free_array(argv, argc);
		wait(NULL);
		kill(pid, SIGKILL);
	}
}