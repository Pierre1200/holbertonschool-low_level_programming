#include "main.h"

/**
* check_prime - Fonction auxiliaire pour vérifier la primauté.
* @n: Le nombre à tester.
* @divisor: Le diviseur actuel que l'on teste.
*
* Return: 1 si le nombre est premier, 0 sinon.
*/
int check_prime(int n, int divisor)
{
	if (divisor * divisor > n)
	{
		return (1);
	}

	if (n % divisor == 0)
	{
		return (0);
	}

	return (check_prime(n, divisor + 1));
}

/**
* is_prime_number - Vérifie si un nombre est premier.
* @n: Le nombre à vérifier.
*
* Return: 1 si n est premier, 0 sinon.
*/
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}

	return (check_prime(n, 2));
}
