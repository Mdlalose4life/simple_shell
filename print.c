#include "shell.h"
#include <stdio.h>
#include <unistd.h>
/**
 * putch - prints the characters
 * @ch: character to be printed
 * Return: 0 Always
 */
int putch(char ch)
{
return (write(1, &ch, 1));
}
/**
 * print - prints a string
 * @str: string value
 */
void print(char *str)
{
while (*str != '\0')
{
	putch(*str);
	str++;
}
}
/**
 * get_grid - prints in a grid
 * @grid: pointer of pointer to a value
 */
void get_grid(char **grid)
{
int index;
for (index = 0; grid[index] != NULL; index++)
{
	print(grid[index]);
	putch('\n');
}
}
/**
 * print_error - prints the error messages to stderr
 * @error: error messages
 */
void print_error(char *error)
{
while (*error != '\0')
{
	write(STDERR_FILENO, error, 3);
	error++;
}
}
