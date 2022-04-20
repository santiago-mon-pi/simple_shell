#ifndef _MAIN_H_
#define _MAIN_H_
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

extern char **environ;

int arg_count(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void free_array(char **argv, int argc);
char **args_v(char *strings, int argc);
int _strcmp(char *s1, char *s2);
char *path_tk(char *path, char *tk);
char *_strcat(char *dest, char *src);
char *path_acc(char *tk_buf, char *tk, char *cmd, char *path);
char *path_validator(char *cmd, char **argv, int argc, char *tmp);

#endif