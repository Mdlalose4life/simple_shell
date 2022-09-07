#include "shell.h"

/**
 *
 *
 */
void handle_files(int signum)
{
(void) signum;
print("\n");
prompt();
}
/**
 *
 *
 *
 */
void write_newline(char *str, ssize_t input)
{
if (str[input - 1] == '\n')
str[input - 1] = '\0';
}
/**
 *
 *
 *
 *
 */
int right_exitarg(char *arg, int len)
{
int index;
for (index = 0; index < len; index++)
{
if (arg[index] < '0' || arg[index] > '9')
{
return (0);
}
}
return (1);
}
