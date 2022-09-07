#include "shell.h"
/**
 *
 *
 *
 */
char **new_env(char **env)
{
int c = 0, len_env;
char **tmp;
for (c = 0; env[c]; c++)
;
len_env = c;
tmp = malloc(sizeof(char *) * (len_env + 1));
for (c = 0; c < len_env; c++)
{
tmp[c] = _strdup(env[c]);
if (tmp[c] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
}
tmp[c] = NULL;
return (tmp);
}
/**
 *
 *
 */
void free_env(char **env)
{
int c;
for (c = 0; env[c]; c++)
free(env[c]);
free(env);
}
/**
 *
 *
 *
 *
 */
void _memset(void *s, int c, size_t n)
{
size_t index;
for (index = 0; index < n; index++)
*((char *) s + index) = c;
}
