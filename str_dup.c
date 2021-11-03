#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string of chars
 * Return: address of the newly allocated memory
 */

char *_strdup(char *str)
{
unsigned int len = 0;
unsigned int i = 0, j = 0;
char *str_copy = NULL;
char *tmp = str;
if (str == NULL)
return (NULL);
i = 0;
while (*str++)
i++;
len = i;
str = tmp;
str_copy = malloc(len * sizeof(char) + 1);
if (str_copy == NULL)
return (NULL);

j = 0;
while (j < len)
{
str_copy[j] = str[j];
j++;
}
str_copy[j] = '\0';
return (str_copy);
}

/**
 * _memset - fills memory with a constant byte
 * @s: param defined in main, pointer to memory area
 * @b: param defined in main, constant byte
 * @n: parame defined in main, number of bytes to be filled
 * Return: memory address of function
 */

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
char *tmp = s;
for (i = 0; i < n; i++)
{
*s = b;
s++;
}
s = tmp;
return (s);
}
