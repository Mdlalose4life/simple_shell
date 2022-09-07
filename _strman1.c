#include "shell.h"
/**
 * _sstrcmp - compares smaller str part to the larger
 * @s1: first string
 * @s2: second string
 * Return: 0
 */
int _sstrcmp(const char *s1, const char *s2)
{
int i, len1, len2, len_s;
len1 = _strlen(s1);
len2 = _strlen(s2);
len_s = _minimum(len1, len2);
for (i = 0; i < len_s; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}
return (0);
}
/**
 * _maximum - finds the maximum of the two numbers
 * @x: first_number
 * @y: second_number
 * Return: maximum number
 */
int _maximum(int x, int y)
{
if (x > y)
return (x);
return (y);
}
/**
 * _minimum - finds the minimum of two numbers
 * @x: first_number
 * @y: second_number
 * Return: minimum number
 */
int _minimum(int x, int y)
{
if (x < y)
return (x);
return (y);
}
/**
 * _strcmp - compare two strings
 * @dest: first string
 * @src: second string
 * Return: < 0 if s1 < s2, > 0 if s2 > s1, 0 strings match
 */
int _strcmp(const char *dest, const char *src)
{
int i = 0, j = 0;
for ( ; dest[i] != '\0'; i++)
{
if (dest[j] != src[j])
break;
j++;
}
return (dest[j] - src[j]);
}
