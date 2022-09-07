#include "shell.h"

/**
 *
 *
 *
 *
 *
 */
char *get_cmd_fpath(char *cmd, char **env) {
  unsigned long int index = 0, join = 0, full_command_length = 0;
  char *MY_PATH = NULL, *tok = NULL, *full_command_path = NULL;
  unsigned long int MY_PAYH_len = 0;
  struct stat st;
  if (cmd[0] == '/')
    return (cmd);
  for (index = 0; env[index] != NULL; index++) 
  {
    if (_strncmp(env[index], "PATH=", 5) == 0) {
      MY_PAYH_len = _strlen(env[index]) - 4;
      MY_PATH = malloc(sizeof(char) * MY_PAYH_len);
      if (MY_PATH == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
      }
      break;
    }
  }
  if (MY_PATH == NULL)
    return (cmd);
  for (join = 5; join < MY_PAYH_len + 5; join++)
    MY_PATH[join - 5] = env[index][join];
  tok = strtok(MY_PATH, ":");
  while (tok != NULL) 
  {
    full_command_length = _strlen(tok) + _strlen(cmd) + 2;
    full_command_path = malloc(sizeof(char) * full_command_length);
    if (full_command_path == NULL)
    {
      perror("malloc");
      return (NULL);
    }
    _memset(full_command_path, 0, full_command_length);
    full_command_path = _strcat(full_command_path, tok);
    full_command_path = _strcat(full_command_path, "/");
    full_command_path = _strcat(full_command_path, cmd);
    if (stat(full_command_path, &st) == 0) {
      free(MY_PATH);
      return (full_command_path);
    }
    free(full_command_path);
    tok = strtok(NULL, ":");
  }
  free(MY_PATH);
  return (cmd);
}
