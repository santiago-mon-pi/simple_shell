#include "main.h"

/**
 * create_path_extension - create a path extencion in command
 * @cmd: command to interprate
 * @argv: arguments
 * @argc: count arguments
 *
 * Return: path with the command
 */
char *create_path_extension(char *cmd, char **argv, int argc)
{

	char *environment_path = NULL, *tokenzer = NULL, *token_buf = NULL;

	if (cmd[0] != '/')
	{
		environment_path = get_path();
		if (environment_path == NULL)
		{
			free_double_pointer(argv, argc);
			perror("./hsh");
		}
		tokenzer = get_route_bin(environment_path, tokenzer);
		token_buf = validate_access(cmd, tokenzer, argv, argc);
		if (token_buf == NULL)
		{
			free_double_pointer(argv, argc);
			perror("./hsh");
		}
		return (token_buf);
	}
	return (cmd);
}

/**
 * get_path - get path in environment
 *
 * Return: path if not find, rerun NULL
 */
char *get_path()
{
	char *ret_path = NULL;
	int i, path_len = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], "PATH") == 0)
		{
			path_len = _strlen(environ[i]);
			ret_path = malloc(sizeof(char) * (path_len + 1));
			if (ret_path == NULL)
			{
				return (NULL);
			}
			ret_path = _strcpy(ret_path, environ[i]);
		}
	}
	return (ret_path);
}

/**
 * get_route_bin - Split the path and the token to keep only the path
 * @path: str to be split with strtok
 * @token: pointer to the str after =
 *
 * Return: token with the correct str
 */
char *get_route_bin(char *path, char *token)
{
	token = strtok(path, "=");
	token = strtok(NULL, "=");
	token = strtok(token, ":");
	return (token);
}

/**
 * validate_access - check wheter the file exist or not in the path
 * @tokenizer: stores tokenization
 * @cmd: command
 * @argc: argument count
 * @argv: argument variables
 *
 * Return: temp if access worked - NULL otherwise
 */

char *validate_access(char *cmd, char *tokenizer, char **argv, int argc)

{
	int tokenizer_len = 0;
	char *ret_token = NULL;

	while (tokenizer != NULL)
	{
		tokenizer_len = _strlen(tokenizer);
		ret_token = malloc(sizeof(char) * (tokenizer_len + _strlen(cmd) + 2));

		if (ret_token == NULL)
		{
			free_double_pointer(argv, argc);
			return (NULL);
		}
		ret_token = _strcpy(ret_token, tokenizer);
		ret_token = _strcat(ret_token, "/");
		ret_token = _strcat(ret_token, cmd);

		if (access(ret_token, X_OK) == 0)
		{
			free(cmd);
			return (ret_token);
		}

		else
		{
			ret_token = cmd;
		}
		tokenizer = strtok(NULL, ":");
	}
	return (ret_token);
}
