#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: String 1 to compare
 * @s2: String 2 to compare
 * Return: 0 if the two strings are identical, 1 otherwise
 */

int _strcmp(char *s1, char *s2)
{
while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
{
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (1);
}
