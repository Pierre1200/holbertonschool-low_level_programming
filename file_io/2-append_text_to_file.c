#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	ssize_t bytes_written;

	/* 1. Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* 2. Open the file: Write Only and Append. NO O_CREAT! */
	/* We don't need a 3rd argument because we don't create it */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* 3. If text_content is not NULL, calculate length and write */
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;

		bytes_written = write(fd, text_content, len);
		if (bytes_written == -1 || bytes_written != len)
		{
			close(fd);
			return (-1);
		}
	}

	/* 4. Clean up and return success */
	close(fd);

	return (1);
}
