#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: string passed by main or by another function
 * @src: string passed by main or by another function
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
char *tmp = NULL;
tmp = dest;
while (*dest != '\0')
{
dest++;
}
while (*src != '\0')
{
*dest = *src;
src++;
dest++;
}
*dest++ = '\0';
dest = tmp;
return (dest);
}
