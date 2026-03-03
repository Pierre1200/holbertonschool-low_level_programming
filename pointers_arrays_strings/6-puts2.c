#include "main.h"
/**
 * puts2 - prints every other character of a string
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
	i += 2;
	_putchar(str[i]);
}
_putchar('\n');
}
