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
 * handle_cmd - dispatches the command lines to handle_path_cmd
 * @av: double pointer
 * @counter: tracking the number of commands that have been executed or failed
 * @array_buf: array_buf: pointer to array of pointers to the args
 * @array_path: pointer to array of pointers to the PATH directories
 * @str_buf_path: pointer to the command argument
 * Return: exit status, return value of the fork_n_exec function (0 or -1)
 */

int handle_cmd(char **av, int counter, char **array_buf, char **array_path, char *str_buf_path)
{
int k = 0, flag = 0, exit_status = 0;
while (array_buf[0][k] != '\0')
{
if (array_buf[0][k] == '/')
{
flag = 1;
break;
}
k++;
}
if (flag == 1)
exit_status = handle_path_cmd(av, counter, array_buf), flag = 0;
else if (flag == 0)
exit_status = handle_nopath_cmd(array_path, av, array_buf,
counter, str_buf_path);
return (exit_status);
}

/**
 * handle_path_cmd - handles command lines consisting of strings
 * @av: double pointer
 * @counter: tracking the number of commands that have been executed or failed
 * @array_buf: array_buf: pointer to array of pointers to the args
 * Return: exit status, return value of the fork_n_exec function (0 or -1)
 */

int  handle_path_cmd(char **av, int counter, char **array_buf)
{
int status = 0, exit_status = 0;
status = _status(array_buf[0]);
if (status == -1)
{
_print(av[0]);
_print(": ");
print_number(counter);
_print(": ");
_print(array_buf[0]);
_print(": not found\n");
exit_status = 127;
free(array_buf);
}
else if (status == 0)
{
exit_status = fork_n_exec(array_buf[0], array_buf);
free(array_buf);
}
return (exit_status);
}

/**
 * handle_nopath_cmd - handles cmd lines consisting of strings w/o PATH dir
 * @array_path: pointer to array of pointers to the PATH directories
 * @av: double pointer
 * @array_buf: array_buf: pointer to array of pointers to the args
 * @counter: tracking the number of commands that have been executed or failed
 * @str_buf_path: pointer to the command argument
 * Return: exit status, return value of the fork_n_exec function (0 or -1)
 */

int handle_nopath_cmd(char **array_path, char **av, char **array_buf, int counter, char *str_buf_path)
{
int exit_status = 0;
if (array_path != NULL && array_path[0] != NULL)
{
str_buf_path = buf_path_cat(counter, av[0], array_buf[0], array_path);
if (str_buf_path != NULL)
{
exit_status = fork_n_exec(str_buf_path, array_buf);
free(str_buf_path);
}
else
exit_status = 127;
free(array_buf);
}
else
free(array_buf);
return (exit_status);
}

/**
 * fork_n_exec - program that executes a command in a child process
 * @str_buf_path: pointer to the cmd argument
 * @array_buf: pointer to array of pointers to args
 * Return: 0 if executable, -1 if not
 */

int fork_n_exec(char *str_buf_path, char **array_buf)
{
int exec_status = 0, exit_status = 0;
pid_t pid;
int status;
pid = fork();
if (pid == -1)
{
perror("Error");
exit(1);
}
if (pid == 0)
{
exec_status = execve(str_buf_path, array_buf, environ);
if (exec_status == -1)
{
perror(array_buf[0]);
exit(127);
}
}
else
wait(&status);
if (WIFEXITED(status))
exit_status = WEXITSTATUS(status);
return (exit_status);
}
