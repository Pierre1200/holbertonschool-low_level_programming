#include "main.h"
/**
 * puts_half - prints half of a string
 * @str: string to be treated
 *
 * Return: void
 */

void puts_half(char *str)
{
int i = 0;
int lon = 0;
	while (str[lon] != '\0')
	{
		lon++;
	}
	i = (lon + 1) / 2;
		while (str[i] != '\0')
		{
			_putchar(str[i]);
			i++;
		}
_putchar('\n');
}
