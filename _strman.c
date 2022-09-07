#include "shell.h"
#include <stdio.h>
#include <string.h>
/**
 * _strlen - Returns the length of a string.
 * @s: The string to be counted.
 * Return: The number of the counted character on a string.
 */
int _strlen(const char *s)
{
int _strlen = 0;
while (*s++)
_strlen++;
return (_strlen++);
}
/**
 * _strcpy - Coppies the string pointed by src including null character
 * to buffer pointed by dest.
 * @dest: The buffer to coppy to.
 * @src: The buffer to coppy from.
 * Return: dest
 */
char *_strcpy(char *dest, const char *src)
{
int i = 0;
while (src[i] != '\0')
{
  dest[i] = src[i];
  i++;
}
return (dest = '\0');
}
/**
 * _strcat -> A function that concatenates two strings.
 * @src: First sting to be concanated.
 * @dest: Second string to be concanated.
 * Return: concanated string called dest
 */
char *_strcat(char *dest, const char *src)
{
int i, l;
i = 0;
l = 0;
while (dest[i++])
	l++;

for (i = 0; src[i]; i++)
	dest[l++] = src[i];
return (dest);
}
/**
 * _strncmp - compares n charas in two strings
 * @dest: destination string
 * @src: source string
 * @n: length of char in a string
 * Return: 0 if match or int value of differences
 */
int _strncmp(char *dest, char *src, int n)
{
int index;
for (index = 0; index < n - 1; index++)
{
if (dest[index] == '\0' || src[index] == '\0')
break;
if (dest[index] != src[index])
break;
}
return (dest[index] - src[index]);
}
