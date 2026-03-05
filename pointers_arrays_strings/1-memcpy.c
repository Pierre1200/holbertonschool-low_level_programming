#include "main.h"

/**
* _memcpy - copies memory area
* @dest: memory area where data is copied to
* @src: memory area where data is copied from
* @n: number of bytes to copy
*
* Return: pointer to dest
*/
char *_memcpy(char *dest, char *src, unsigned int n)

{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
return (dest);
}
