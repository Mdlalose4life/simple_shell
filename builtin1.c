#include "shell.h"
#include <unistd.h>
/**
 *_setenv - sets env variable
 * @env: The env variables
 * Return: 0. Success
 */
int _setenv(char ***env)
{
char *env_var, *env_val;
env_var = strtok(NULL, " \n");
if (env_var == NULL)
{
perror("missing argument\n");
return (1);
}
env_val = strtok(NULL, " \n");
if (env_val == NULL)
{
perror("missing value\n");
return (1);
}
return (_setenv_fun(env, env_var, env_val));
}
/**
 * _setenv_fun - helps setting the environment.
 * @env_var: first env variable
 * @env_varl: second env vaarible
 * @env: the env variabes
 * Return: 0 success
 */
int _setenv_fun(char ***env, char *env_var, char *env_val)
{
char **new_env;
int i;
for (i = 0; (*env)[i] != NULL; i++)
{
if (_sstrcmp((*env)[i], env_var) == 0)
{
free((*env)[i]);
(*env)[i] = new_path_str(env_var, env_val);
return (0);
}
}
new_env = grow_env(*env, i);
if (env == NULL)
{
perror("grow_env");
return (1);
}
free(*env);
*env = new_env;
(*env)[i] = new_path_str(env_var, env_val);
print((*env)[i]);
putch('\n');
(*env)[++i] = NULL;
return (0);
}
/**
 * grow_env - grwos the current env
 * @env: the current env.
 * @env_size: the size of the env minus \0.
 * Return: NULL if there is memory errors
 * otherwise the grown env.
 */
char **grow_env(char **env, int env_size)
{
int i;
char **new_env;
new_env = malloc(sizeof(char **) * (env_size + 2));
if (new_env == NULL)
{
perror("malloc");
return (NULL);
}
for (i = 0; i < env_size; i++)
new_env[i] = env[i];
return (new_env);
}
/**
 * new_path_str - New string
 * env_val: env variable name
 * env_val: env variable value
 * Return: path to the new string.
 */
char *new_path_str(char *env_var, char *env_val)
{
int env_var_len, env_val_len, path_length = 0;
char *path_str;
env_var_len = _strlen(env_var);
env_val_len = _strlen(env_val);
path_length = env_var_len + env_val_len + 2;
path_str = malloc(sizeof(char) * (path_length));
if (path_str == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
_memset(path_str, '\0', path_length);
path_str = _strcat(path_str, env_var);
path_str = _strcat(path_str, "=");
path_str = _strcat(path_str, env_val);
return (path_str);
}
