#ifndef SHELL_H
#define SHELL_H

#ifndef BUF_SIZE
#define BUF_SIZE 256
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>

void repl_newline(char *str, ssize_t input);
char *get_cmd_fpath(char *cmd, char **env);

void _memset(void *s, int c, size_t n);
int _strncmp(char *s1, char *s2, int n);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);

void prompt(void);
void put_grid(char **grid);
int right_exitarg(char *arg, int lenght);

int interactive(void);
void print(char *s);
int putch(char ch);

int _setenv(char ***env);
int _setenv_fun(char ***env, char *env_var, char *env_val);
char **grow_env(char **env, int env_size);
char *new_path_str(char *env_var, char *env_val);
int _unsetenv(char ***env);
void recoil_env(char ***env, int del);
int _atoin(const char *s, int len);
void ihelp(void);
void punctuate_handler(int signum);

int _sstrcmp(const char *s1, const char *s2);
int _maximum(int x, int y);
int _minimum(int x, int y);
int _strcmp(const char *dest, const char *src);

char **new_env(char **env);
void free_env(char **env);
void _memset(void *s, int c, size_t n);

void ESC_comments(char *lineptr);
char exec_builtins(char *cmd, char *lineptr
__attribute__ ((unused)), char ***env);
char cmd_execution(char *cmd, char *lineptr, char ***env);
char **current_env(char **env);
#endif
