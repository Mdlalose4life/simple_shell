#include "shell.h"
/**
 *
 */
void prompt(void)
{
print("$ ");  
}
/**
 *
 *
 *
 */
int interactive(void)
{
struct stat filest;
if (fstat(0, &filest) == -1)
{
perror("fstat");
exit(EXIT_FAILURE);
}
if (S_ISFIFO(filest.st_mode))
{
return (0);
}
return (1);
}
