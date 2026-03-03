#include "main.h"
/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: the integer value of the string
 */

int _atoi(char *s)
{
int i = 0;
int res = 0;
int sig = 1;
int found = 0;

while (s[i] != '\0')
{
	if (found == 0 && s[i] == '-')
	{
		sig *= -1;
	}
	else if (s[i] >= '0' && s[i] <= '9')
	{
		found = 1;
		res = res * 10 - (s[i] - '0');
	}
	else if (found == 1)
	{
		break;
	}
	i++;
}
if (sig == 1)
	return (-res);
else
	return (res);
}

