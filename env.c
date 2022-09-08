#include "shell.h"
/**
 * new_env - returns the current env variables.
 * @env: The env variable
 * Return: double pointer to env variable.
 */
char **new_env(char **env)
{
int count = 0, var_len;
char **temp;
for (count = 0; env[count]; count++)
	var_len = count;
temp = malloc(sizeof(char *) * (var_len + 1));
for (count = 0; count < var_len; count++)
{
temp[count] = _strdup(env[count]);
if (temp[count] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
}
temp[count] = NULL;
return (temp);
}
/**
 * free_env - free env varible's memory
 *@env: env varible
 */
void free_env(char **env)
{
int index;
for (index = 0; env[index]; index++)
free(env[index]);
free(env);
}
/**
 * _memset - starts memory array
 * @s: memory of an array
 * @c: The starting value
 * @n: Requred memory
 */
void _memset(void *s, int c, size_t n)
{
size_t index;
for (index = 0; index < n; index++)
*((char *) s + index) = c;
}
