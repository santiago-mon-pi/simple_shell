#ifndef _MAIN_H_
#define _MAIN_H_
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>

extern char **environ;

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *c);
int arg_count(char *str);
char **args_v(char *strings, int argc);
void free_array(char **argv, int argc);
void _exec(char **argv, char *buf, int argc, int count);
char *path_validator(char *cmd, char **argv, int argc, char *tmp);
char *path_tk(char *path, char *tk);
char *path_acc(char *tk_buf, char *tk, char *cmd, char *path);
void fork_process(char **argv, char *buf, int argc, int count);
void system_error(char **argv, int count, char *error);
void print_num(int n);
char *path_ciclo();

#endif
