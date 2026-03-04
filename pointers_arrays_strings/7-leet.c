#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: string to be encoded
 *
 * Return: pointer to the encoded string
 */

char *leet(char *str)
{
	int i = 0;
	int j = 0;
	char l[] = "aAeEoOtTlL";
	char r[] = "4433007711";

	while (str[i] != '\0')
	{
		for (j = 0; l[j] != '\0'; j++)
		{
			if (str[i] == l[j])
			{
				str[i] = r[j];
			}
		}
		i++;
	}
	return (str);
}
