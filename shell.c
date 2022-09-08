#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
/**
 * main - Central and entry point for this program.
 * @ac: Argument count.
 * @av: Argument vectore.
 * @env: environments variable passed to child proccess.
 * Return: 0 Always
 */
int main(int ac __attribute__ ((unused)), char *av[], char **env)
{
FILE *stream = 0;
char *ptr_line = NULL;
char *command = NULL;
size_t slen = 0;
ssize_t input = 0;
stream = stdin;
env = new_env(env);
if (signal(SIGINT, punctuate_handler) == SIG_IGN)
signal(SIGINT, SIG_IGN);
while (1)
{
if (interactive())
prompt();
input = getline(&ptr_line, &slen, stream);
if (stream == NULL)
{
perror(av[0]);
return (EXIT_FAILURE);
}
if (input == EOF)
{
free(ptr_line);
free_env(env);
if (errno == 0)
return (EXIT_SUCCESS);
perror(av[0]);
return (EXIT_FAILURE);
}
esc_comments(ptr_line);
command = strtok(ptr_line, " \n");
if (command != NULL && exec_builtins(command, ptr_line, &env))
{
if (command_execution(command, ptr_line, &env))
{
free_env(env);
perror(av[0]);
return (EXIT_FAILURE);
}
}
}
return (EXIT_SUCCESS);
}
