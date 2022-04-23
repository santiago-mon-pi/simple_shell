#include "main.h"

char *path_ciclo()
{
	char *path_buff = NULL;
	int i, env_len = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], "PATH") == 0)
		{
			env_len = strlen(environ[i]);
			path_buff = malloc(sizeof(char) * (env_len + 1));
			if (path_buff == NULL)
			{
				perror("ERROR");
			}
			path_buff = _strcpy(path_buff, environ[i]);
		}
	}
	return (path_buff);
}
char *path_validator(char *cmd, char **argv, int argc, char *tmp)
{
	int tk_len = 0;
	char *path_buff, *tk = NULL, *tmp_tk;

	if (cmd[0] != '/')
	{

		tk = path_ciclo(path_buff, tk);
		while (tk != NULL)
		{
			tk_len = _strlen(tk);
			tmp_tk = malloc(sizeof(char) * (tk_len + _strlen(cmd) + 2));
			if (tmp_tk == NULL)
			{
				free_array(argv, argc);
				free(tmp);
				free(path_buff);
				perror("ERROR");
			}
			tmp_tk = path_acc(tmp_tk, tk, cmd, path_buff);
			if (tmp_tk != NULL)
				return (tmp_tk);
			tmp_tk = strtok(NULL, ";");
		}
		free(path_buff);
		return (cmd);
	}
	return (cmd);
}

char *path_tk(char *path, char *tk)
{
	tk = strtok(path, "=");
	tk = strtok(NULL, "=");
	tk = strtok(tk, ":");
	return (tk);
}

char *path_acc(char *tk_buf, char *tk, char *cmd, char *path)
{
	tk_buf = _strcpy(tk_buf, tk);
	tk_buf = _strcat(tk_buf, "/");
	tk_buf = _strcat(tk_buf, cmd);
	if (access(tk_buf, X_OK) == 0)
	{
		free(path);
		free(cmd);
		return (tk_buf);
	}
	free(tk_buf);
	tk_buf = NULL;
	return (tk_buf);
}
