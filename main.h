#ifndef __MAIN__H
#define __MAIN__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

/*string functions*/
int _strlen(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);

/*display functions*/
char **tokenn(char *str);
int get(int status, char ***args);
void print_env(char **env);
char *path(char *input, char *path);
int exec_cmd(char *str, char *strr, char **stri, int error);
int check_cmd(char **input, char *av, char *path_line, int error);

/*print functions*/
void print_number(int n);
void print(char *input, char *cmd, int error);
void free_arr(char **arr);
char *envr(char *path);
int slash(char *str);
#endif
