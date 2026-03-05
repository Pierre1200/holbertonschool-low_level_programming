#include "main.h"

/**
 * puts2 - prints every other character of a string, starting with the first
 * @str: the string to be treated
 *
 * Return: void
 */

void puts2(char *str)
{
	int i = 0;
	int j = 0;

	while (str[j] != '\0')
	{
		j++;
	}

	while (i < j)
	{
		_putchar(str[i]);
		i += 2;
	}
	_putchar('\n');
}
