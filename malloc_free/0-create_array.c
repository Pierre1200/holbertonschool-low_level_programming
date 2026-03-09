#include "main.h"
#include <stdlib.h>

/**
* create_array - creates an array of chars...
* @size: the size of the memory to print
* @c: char to initialize with
*
* Return: pointer to array or NULL
*/

char *create_array(unsigned int size, char c)
{
	char *ptr;

	unsigned int i = 0;

	if (size == 0)
	{
		return (NULL);
	}
	ptr = malloc(sizeof(char) * size);
	if (ptr == NULL)
		{
		return (NULL);
		}
	while (i < size)
	{
		ptr[i] = c;
		i++;
	}
	return (ptr);
}
