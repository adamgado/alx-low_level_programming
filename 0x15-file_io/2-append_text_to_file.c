#include "main.h"
/**
 * append_text_to_file - append text at the end of file.
 * @filename: pointer to file name.
 * @text_content: string to add to end of file.
 * Return: 1 on success, -1 on fail.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, byte_written, str_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (str_length = 0; text_content[str_length];)
			str_length++;
	}

	file_descriptor = open(filename, O_WRONLY | O_APPEND);
	byte_written = write(file_descriptor, text_content, str_length);

	if (file_descriptor == -1 || w == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}
