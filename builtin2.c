#include "shell.h"
/**
 *
 *
 *
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
shrink_env(env, i);
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
 *
 *
 *
 */
void shrink_env(char ***env, int del)
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
 *
 *
 *
 *
 */
int _atoin(const char *s, int len)
{
int i, base, res, digit;
res = 0;
base = 1;
for (i = 0; i < len; i++)
{
digit = s[len - i - 1] - 48;
res += digit *base;
base = base * 10;
}
return (res);
}
/**
 *
 */
void ihelp(void)
{
print("SUPPORTED COMMANDS\n");
print("#\t\t\t\tAdd a comment\n");
print("env\t\t\t\tPrint the environment variables.\n");
print("exit [n]\t\t\tExit the shell.\n");
print("help\t\t\t\tDisplay this help.\n");
}
