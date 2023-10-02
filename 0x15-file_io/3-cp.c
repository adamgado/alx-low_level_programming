#include "main.h"
#include <stdio.h>
/**
 * errors_file - check for errors
 * @file_from: file to copy
 * @file_to: copy destination
 * @argv: An array of pointers to the arguments.
 */
void errors_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1])
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2])
		exit(99);
	}
}
/**
 * main - Copies the contents of a file to another.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, err_close;
	ssize_t nchars, nwr;
	char buf[1024];

	if (argc != 3)
		{
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			exit(97);
		}
	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_APPEND | O_TRUNC, 0664);
	errors_file(file_from, file_to, argv[]);
	nchars = 1024;

	while(nchars == 1024)
	{
		nchars = read(file_from, buf, 1024);
		if(nchars == -1)
		{
			errors_file(-1, 0, argv);
		}
		nwr = write(file_to, buf, 1024);
		if(nwr == -1)
		{
			errors_file(0, -1, argv);
		}
	}
	err_close = close(file_from);
	if(err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	err_close = close(file_to);
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
	return (0);
}
