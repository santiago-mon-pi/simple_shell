#include "main.h"

/**
 * argv - split a string and create an array of strings
 * @str: the string with data
 *
 * Return: the numbers of strings separate with DELIM
 */

char **argv(char *line, int argument_count)
{
   char **return_newline = NULL, *tmp_line = NULL, *tokenizer = NULL;
   int len_line = 0, i = 0;

 
   return_newline = malloc(sizeof(char *) * (argument_count + 1));
   if (return_newline == NULL)
   {
       perror("Error");
   }

   
   len_line = _strlen(line);
   tmp_line = malloc(sizeof(char) * (len_line + 1));
   if (tmp_line == NULL)
   {
       free(return_newline);
       perror("Error");
   }
   
   tmp_line = _strcpy(tmp_line, line);

  
   tokenizer = strtok(tmp_line, DELIM);
   len_line = 0;
   while (tokenizer != NULL)
   {
       
       len_line = _strlen(tokenizer);
       return_newline[i] = malloc(sizeof(char) * (len_line + 1));
       if (return_newline[i] == NULL)
       {
           free_double_pointer(return_newline, argument_count);
           perror("Error");
       }
       
       return_newline[i] = _strcpy(return_newline[i], tokenizer);
       tokenizer = strtok(NULL, DELIM);
       i++;
   }
  
   return_newline[i] = NULL;
   free(line);
   free(tmp_line);

   return return_newline;
}


/**
 * free_grid - frees a 2 dimensional grid
 * @argv: grid created. (array of pointers)
 * @argc: rows (integer)
 *
 * Return: void. Frees memory
 */
void free_double_pointer(char **argv, int argc)
{
	int i;

	i = 0;
	while (i < argc)
	{
		free(*(argv + i));
		i++;
	}
	free(argv);
}
