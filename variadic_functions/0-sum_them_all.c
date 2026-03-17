#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Returns the sum of all its parameters.
 * @n: The number of parameters passed to the function.
 *
 * Return: If n == 0, return 0.
 * Otherwise, return the sum of all parameters.
 */

int sum_them_all(const unsigned int n, ...)
{
int som = 0;
unsigned int i;
va_list sac;

if (n == 0)
	return (0);

va_start(sac, n);

for (i = 0; i < n; i++)
{
	som = som + va_arg(sac, int);
}
va_end(sac);
return (som);
}
