#include "main.h"
/**
 * create_file - create file.
 * @filename: pointer to the name of the file to create.
 * @text_content: pointer to a string to write to the file.
 * Return: 1 on success or -1 on fail.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, byte_written, str_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (str_length = 0; text_content[str_length];)
			str_length++;
	}

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	byte_written = write(file_descriptor, text_content, str_length);

	if (file_descriptor == -1 || byte_written == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}
