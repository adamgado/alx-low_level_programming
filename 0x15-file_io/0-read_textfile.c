#include "main.h"
/**
 * read_textfile - read text file and print it to standard output.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: bytes written or 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t file_descriptor;
	ssize_t byte_written;
	ssize_t byte_read;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	byte_read = read(file_descriptor, buf, letters);
	byte_written = write(STDOUT_FILENO, buf, byte_read);

	free(buf);
	close(file_descriptor);
	return (byte_written);
}
