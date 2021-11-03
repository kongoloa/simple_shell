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
 * print_number - converts an integer into a string
 * @n: integer passed from main or another function
 * Return: void
 */

void print_number(int n)
{
unsigned int m;
if (n > 9)
{
print_number(n / 10);
_putchar('0' + (n % 10));
}
else if (n > -1)
{
_putchar('0' + n);
}
else if (n > -10)
{
_putchar('-');
n = n * (-1);
_putchar('0' + n);
}
else
{
_putchar('-');
n = n * (-1);
m = (unsigned int) n;
print_number(m / 10);
_putchar('0' + (m % 10));
}
}

/**
 * _print - prints on standard output
 * @str: string to be printed
 * Return: return of write, number of chars that write prints
 */

int _print(char *str)
{
return (write(STDOUT_FILENO, str, _strlen(str)));
}
