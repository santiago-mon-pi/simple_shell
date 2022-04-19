#ifndef _MAIN_H_
#define _MAIN_H_
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int arg_count(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif