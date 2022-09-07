#include "shell.h"
/**
 * prompt - prints the prompt on the screen
 */
void prompt(void)
{
print("$ ");
}
/**
 * interactive - checks mode of interaction
 * Returns: 0 if interation is pipe.
 * otherwise return 1 if interation mode is not pipe.
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
