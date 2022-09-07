#include "shell.h"

/**
 *
 *
 *
 *
 *
 */
char *get_cmd_fpath(char *cmd, char **env)
{
unsigned long int i = 0, j = 0, full_cmd_len = 0;
char *PATH_value = NULL, *token = NULL, *full_cmd_path = NULL;
unsigned long int PATH_value_len = 0;
struct stat st;
if (cmd[0] == '/')
return (cmd);
for (i = 0; env[i] != NULL ; i++)
{
if (_strncmp(env[i], "PATH=", 5) == 0)
{
PATH_value_len = _strlen(env[i]) - 4;
PATH_value = malloc(sizeof(char) * PATH_value_len);
if (PATH_value == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
break;
}
}
if (PATH_value == NULL)
return (cmd);
for (j = 5; j < PATH_value_len + 5; j++)
PATH_value[j - 5] = env[i][j];
token = strtok(PATH_value, ":");
while (token != NULL)
{
full_cmd_len = _strlen(token) + _strlen(cmd) + 2;
full_cmd_path = malloc(sizeof(char) * full_cmd_len);
if (full_cmd_path == NULL)
{
perror("malloc");
return (NULL);
}
_memset(full_cmd_path, 0, full_cmd_len);
full_cmd_path = _strcat(full_cmd_path, token);
full_cmd_path = _strcat(full_cmd_path, "/");
full_cmd_path = _strcat(full_cmd_path, cmd);
if (stat(full_cmd_path, &st) == 0)
{
free(PATH_value);
return (full_cmd_path);
}
free(full_cmd_path);
token = strtok(NULL, ":");
}
free(PATH_value);
return (cmd);
}
