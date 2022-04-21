#include "main.h"
/**
 * *path_validator - check the PATH
 * @cmd: comand
 * @argv: double pointer with the argument and the len of argument
 * @argc: size of argument
 * @tmp: pointer for temporal content
 * Return: the command
 */
char *path_validator(char *cmd, char **argv, int argc, char *tmp)
{
	int env_len = 0, tk_len = 0, i;
	char *path_buf, *tk = NULL, *tmp_tk;

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
			tmp_tk = malloc(sizeof(char) * (tk_len + _strlen(cmd) + 2));
			if (tmp_tk == NULL)
			{
				free_array(argv, argc);
				free(tmp);
				free(path_buf);
				perror("ERROR");
			}
			tmp_tk = path_acc(tmp_tk, tk, cmd, path_buf);
			if (tmp_tk != NULL)
				return (tmp_tk);
			tmp_tk = strtok(NULL, ";");
		}
		free(path_buf);
		return (cmd);
	}
	return (cmd);
}
/**
 * *path_tk - tokenizer
 * @path: pointer with path
 * @tk: symbols
 * Return: content in tk
 */
char *path_tk(char *path, char *tk)
{
	tk = strtok(path, "=");
	tk = strtok(NULL, "=");
	tk = strtok(tk, ":");
	return (tk);
}
/**
 * *path_acc - validate acces to path
 * @tk_buf: buffer for a copy of tk
 * @tk: pointer with a part of the tokenized input
 * @cmd: comand
 * @path: pointer with PATH copy
 * Return: buffer
 */
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
