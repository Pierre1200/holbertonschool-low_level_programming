#include "main.h"
/**
 * print_sign - print a sign
 * @n: number
 *
 * Return: 1 and prints +, 0 and prints, -1 and prints -
 */

int print_sign(int n)
{
if (n > 0)
{
_putchar ('+');
return (1);
}
	else if (n < 0)
	{
	_putchar ('-');
	return (-1);
	}
		else
		{
		_putchar ('0');
		return (0);
		}
}
