#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int file_descriptor);
/**
 * create_buffer - allocate 1024 bytes for buffer.
 * @file: the file name buffer is storing chars for.
 * Return: a pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buf;

	buffer = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
}
/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int file_descriptor)
{
	int i;

	i = close(file_descriptor);

	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(100);
	}
}
/**
 * main - copies the contents of file to another.
 * @argc: the number of arguments in program.
 * @argv: an array of pointers to the arguments.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, byte_read, byte_written;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	byte_read = read(file_from, buf, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || byte_read == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		byte_written = write(file_to, buf, byte_read);
		if (file_to == -1 || byte_written == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		byte_read = read(file_from, buf, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (byte_read > 0);

	free(buf);
	close_file(file_from);
	close_file(file_to);

	return (0);
}
