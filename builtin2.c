#include "shell.h"
/**
 * _unsetenv - unsets the variables of env.
 * @env: double pointer to the env variable
 * Return: Always 0.
 */
int _unsetenv(char ***env)
{
int i;
char *env_var, *dup;
env_var = strtok(NULL, " \n");
if (env_var == NULL)
{
perror("missing argument\n");
return (1);
}
for (i = 0; (*env)[i] != NULL; i++)
{
dup = strtok(strdup((*env)[i]), "=");
if (_strcmp(dup, env_var) == 0)
{
free(dup);
print("found: ");
print((*env)[i]);
putch('\n');
recoil_env(env, i);
return (0);
}
free(dup);
}
print("not found\n");
print("query: ");
print(env_var);
putch('\n');
return (0);
}
/**
 * recoil_env - recoils the env to a new size.
 * @env: triple pointer to the env variable
 * @del: the recoiled env variable size.
 */
void recoil_env(char ***env, int del)
{
int i, env_size;
char **new_env;
for (i = 0; (*env)[i] != NULL; i++)
;
env_size = i;
new_env = malloc(sizeof(char *) * (env_size));
for (i = 0; i < del; i++)
{
new_env[i] = _strdup((*env)[i]);
if (new_env[i] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
}
for (i = del; (*env)[i] != NULL; i++)
{
if ((*env)[i + 1] != NULL)
new_env[i] = _strdup((*env)[i + 1]);
else
new_env[i] = NULL;
}
free_env(*env);
*env = new_env;
}
/**
 * _atoin - Changes strings to intergers
 * @s: pointer to a string
 * @len: character legth of string
 * Return: The interger presentation of a sring
 */
int _atoin(const char *s, int len)
{
int i, b, r, d;
r = 0;
b = 1;
for (i = 0; i < len; i++)
{
d = s[len - i - 1] - 48;
r += d*b;
b = b * 10;
}
return (r);
}
/**
 * ihelp - immitates the bultin help commands
 */
void ihelp(void)
{
print("SUPPORTED COMMANDS\n");
print("#\t\t\t\tAdd a comment\n");
print("env\t\t\t\tPrint the environment variables.\n");
print("exit [n]\t\t\tExit the shell.\n");
print("help\t\t\t\tDisplay this help.\n");
}
