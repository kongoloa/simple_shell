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
 * env_ - prints the current environment on stdd output
 * @array_buf: pointer to array of pointers to the args
 * @buf: command line passed in by the user on standard input
 * @path_str: pointer to the PATH string
 * @array_path: pointer to array of pointers to the PATH directories
 * @exit_status: 0 if the prev command was found, -1 if the cmd was not found
 * Return: void
 */

void env_(char **array_buf, char *buf, char *path_str, char **array_path, int exit_status)
{
int i = 0;
(void)path_str;
(void)array_path;
(void)exit_status;
for (i = 0; environ[i]; i++){
_print(environ[i]), _print("\n");
}
free(array_buf);
free(buf);
}
