#include <stdio.h>
#include "variadic_functions.h"
#include <stdarg.h>

/**
* print_strings - Prints strings, followed by a new line.
* @separator: The string to be printed between the strings.
* @n: The number of strings passed to the function.
*
* Return: void.
*/

void print_strings(const char *separator, const unsigned int n, ...)
{
unsigned int i;
va_list sac;
char *str;

va_start(sac, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(sac, char *);
			if (str == NULL)
			{
				printf("(nil)");
			}
			else
			{
			printf("%s", str);
			}
			if (separator != NULL && i < n - 1)
			{
				printf("%s", separator);
			}
	}
va_end(sac);
printf("\n");
}
