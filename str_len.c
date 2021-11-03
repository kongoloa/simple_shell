#include "shell.h"

/**
 * _strlen - function that returns the length of a string
 * @s: string defined in main or another function
 * Return: length of string
 */

int _strlen(char *s)
{
int i = 0;
while (*s != '\0')
i++, s++;
return (i);
}
