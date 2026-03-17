#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
* print_numbers - Prints numbers, followed by a new line.
* @separator: The string to be printed between numbers.
* @n: The number of integers passed to the function.
*
* Return: void.
*/

void print_numbers(const char *separator, const unsigned int n, ...)
{
unsigned int i;

va_list sac;

va_start(sac, n);

for (i = 0; i < n; i++)
{
	printf("%d", va_arg(sac, int));
	if (separator != NULL && i < n - 1)
		printf("%s", separator);
}
va_end(sac);
printf("\n");
}
