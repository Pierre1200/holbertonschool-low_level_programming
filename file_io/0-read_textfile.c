#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print.
 * 0 if filename is NULL, open fails, read fails,
 * or if write fails / writes unexpected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	/* 1. Edge case: NULL filename */
	if (filename == NULL)
		return (0);

	/* 2. Open the file in Read-Only mode */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	/* 3. Allocate memory for the buffer */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	/* 4. Read the file into the buffer */
	bytes_read = read(fd, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* 5. Write the buffer to Standard Output (1) */
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	/* 6. Check if write failed or didn't write all the bytes we read */
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* 7. Clean up and return the number of bytes written */
	free(buffer);
	close(fd);

	return (bytes_written);
}
