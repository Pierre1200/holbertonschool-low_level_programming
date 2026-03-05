#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: the string to search in
 * @needle: the substring to look for
 *
 * Return: pointer to the beginning of the located substring, or NULL
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0, j;

	if (*needle == '\0')
		return (haystack);

	while (haystack[i] != '\0')
	{
		for (j = 0; needle[j] != '\0' &&  haystack[i + j] == needle[j]; j++)
		{

		}
		if (needle[j] == '\0')
		{
			return (&haystack[i]);
		}
		i++;
	}
	return (0);
}
