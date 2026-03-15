#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the string to duplicate
 *
 * Return: a pointer to the duplicated string, or NULL if insufficient memory
 */

char *_strdup(char *str)
{
	unsigned int i = 0, lon = 0;
	char *ptr;

	if (str == 0)
	{
		return (NULL);
	}
	while (str[lon] != '\0')
	{
		lon++;
	}
	ptr = malloc(sizeof(char) * (lon + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
	ptr[i] = str[i];
	i++;
	}
ptr[i] = '\0';
return (ptr);
}
