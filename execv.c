#include "shell.h"
/**
 * esc_comments - escapes the comment sections
 * @lineptr: Pointer to the line.
 */
void esc_comments(char *lineptr)
{
const char s[] = " ";
strtok(lineptr, s);
}
/**
 * exec_builtins - executes builtin commands
 * @cmd: the input commands
 * @lineptr: line input pointer
 * @env: triple pointer to env
 * Return: 0 if command is builtin
 * otherwise 1
 */
char exec_builtins(char *cmd, char *lineptr __attribute__
((unused)), char ***env)
{
int exitn, len_arg;
char *arg = NULL;
if (_strncmp(cmd, "exit", 5) == 0)
{
arg = strtok(NULL, " \n");
if (arg != NULL)
{
len_arg = _strlen(arg);
if (right_exitarg(arg, len_arg) == 1)
{
exitn = _atoin(arg, len_arg);
free_env(*env);
free(lineptr);
exit(exitn);
}
print("exit: Illegal number\n");
return (0);
}
free(lineptr);
free_env(*env);
exit(EXIT_SUCCESS);
}
if (_strncmp(cmd, "env", 4) == 0)
{
get_grid(*env);
return (0);
}
if (_strncmp(cmd, "_help", 5) == 0)
{
_help();
return (0);
}
if (_strncmp(cmd, "setenv", 7) == 0)
{
_setenv(env);
return (0);
}
if (_strncmp(cmd, "unsetenv", 9) == 0)
{
_unsetenv(env);
return (0);
}
return (1);
}
/**
 * command_execution - executes the builtin commands
 * @cmd: the commands from the user.
 * @lineptr: Pointer to the user command
 * @env: triple pointer to the env
 * Return: 0 success,
 * return 1 if the is an error.
 */
char command_execution(char *cmd, char *lineptr, char ***env)
{
char *cargv[BUFFER_SIZE], *full_execv_path = NULL;
int index, status;
pid_t pid = fork();
if (pid == -1)
return (1);
if (pid != 0)
{
wait(&status);
}
else
{
cargv[0] = cmd;
for (index = 0; index < BUFFER_SIZE - 1; index++)
{
if (cargv[index] == NULL)
break;
cargv[index + 1] = strtok(NULL, " \n");
}
if (cmd[0] == '.')
full_execv_path = cmd;
else
{
full_execv_path = find_command_path(cmd, *env);
if (full_execv_path == NULL)
{
free(lineptr);
return (1);
}
}
if (execve(full_execv_path, cargv, *env) == -1)
{
free(lineptr);
return (1);
}
}
return (0);
}
