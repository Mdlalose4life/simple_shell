#include "shell.h"

/**
 * punctuate_handler -> ststains the shell  when key is pessed
 * @signum: Punttuates the keys
 */
void punctuate_handler(int signum)
{
(void) signum;
print("\n");
prompt();
}
/**
 * repl_newline -> Replaces a newline with a NULL char.
 * @str: current string.
 * @input: input string
 */
void repl_newline(char *str, ssize_t input)
{
if (str[input - 1] == '\n')
str[input - 1] = '\0';
}
/**
 * right_exitarg -> checks if right exit argument is entered.
 * @arg: arguments
 * @lenght: The length of the argument
 * Return: Always 0.
 */
int right_exitarg(char *arg, int lenght)
{
int index;
for (index = 0; index < lenght; index++)
{
if (arg[index] < '0' || arg[index] > '9')
{
return (0);
}
}
return (1);
}
