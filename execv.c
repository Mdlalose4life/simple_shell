#include "shell.h"
/**
 *
 *
 */
void ESC_comments(char *lineptr)
{
const char s[] = " ";
strtok(lineptr, s);
}
/**
 *
 *
 *
 *
 *
 */
char exec_builtins(char *cmd, char *lineptr __attribute__ ((unused)), char ***env)
{
int exitn, len_arg;
char *arg = NULL;
if (_strncmp(cmd, "exit", 5) == 0)
{
arg = strtok(NULL, " \n");
if (arg != NULL)
{
len_arg = _strlen(arg);
if (valid_exitarg(arg, len_arg) == 1)
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
put_grid(*env);
return (0);
}
if (_strncmp(cmd, "help", 5) == 0)
{
ihelp();
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
 *
 * 
 * 
 * 
 * 
 */
char cmd_execution(char *cmd, char *lineptr, char ***env)
{
char *cargv[BUF_SIZE], *full_exec_path = NULL;
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
for (index = 0; index < BUF_SIZE - 1; index++)
{
if (cargv[index] == NULL)
break;
cargv[index + 1] = strtok(NULL, " \n");
}
if (cmd[0] == '.')
full_exec_path = cmd;
else
{
full_exec_path = get_cmd_fpath(cmd, *env);
if (full_exec_path == NULL)
{
free(lineptr);
return (1);
}
}
if (execve(full_exec_path, cargv, *env) == -1)
{
free(lineptr);
return (1);
}
}
return (0);
}
