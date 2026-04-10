#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - creates a file and writes text content to it
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int len = 0;
	ssize_t bytes_written;

	/* 1. Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* 2. Calculate the length of text_content if it's not NULL */
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	/* 3. Open the file with specific flags and permissions (0600 = rw-------) */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* 4. If there is text to write, write it */
	if (text_content != NULL)
	{
		bytes_written = write(fd, text_content, len);

		/* Check if write failed or didn't write everything */
		if (bytes_written == -1 || bytes_written != len)
		{
			close(fd);
			return (-1);
		}
	}

	/* 5. Clean up and return success */
	close(fd);

	return (1);
}
