#include "main.h"
#include <stdlib.h>

/**
* _calloc - allocates memory for an array, using malloc
* @nmemb: number of elements
* @size: size of each element in bytes
*
* Return: pointer to the allocated memory, or NULL on failure
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i = 0;
	unsigned int total = nmemb * size;

	if (nmemb == 0 || size == 0)
	return (NULL);

	ptr = malloc(size * nmemb);
	if (ptr == NULL)
	return (NULL);

	for (i = 0; i < total; i++)
	{
		ptr[i] = 0;
	}
	return ((void *)ptr);
}
