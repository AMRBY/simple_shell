#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

char *get_line(void);
char **split(char *buffer);
int execute(char **argv, char **av);
extern char **environ;
int _strlen(char *s);
char *_strcat(char *des, const char *sr);
int _strcmp(char *st1, char *st2);
char *_strcpy(char *des, char *sr);

#endif
