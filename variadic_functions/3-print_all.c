#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything based on the format provided.
 * @format: A list of types of arguments passed to the function.
 *
 * Return: void.
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str;
	char *sep = "";
	va_list sac;

	va_start(sac, format);

	if (format != NULL)
	{
		(format[i] != '\0');
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", sep, va_arg(sac, int));
					sep = ", ";
					break;
				case 'i':
					printf("%s%d", sep, va_arg(sac, int));
					sep = ", ";
					break;
				case 'f':
					printf("%s%f", sep, va_arg(sac, double));
					sep = ", ";
					break;
				case 's':
					str = va_arg(sac, char*);
					if (str == NULL)
					{
						str = "(nil)";
					}
					printf("%s%s", sep);
					sep = ", ";
					break;
			}
			i++;
		}
	}
	printf("\n");
	va_end(sac);
}
