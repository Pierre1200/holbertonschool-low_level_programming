#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to be modified
 *
 * Return: pointer to the modified string
 */

char *cap_string(char *str)
{
int j = 0;
int i = 0;
char separators[] = " \t\n,;.!?\"(){}";

while (str[i] != '\0')
{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		if (i == 0)
		{
		str[i] = str[i] - 32;
		}
		else
		{
			for (j = 0; separators[j] != '\0'; j++)
			{
				if (str[i - 1] == separators[j])
				{
					str[i] = str[i] - 32;
					break;
				}
			}
		}
	}
	i++;
}
return (str);
}
