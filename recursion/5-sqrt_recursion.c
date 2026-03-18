#include "main.h"

/**
* find_sqrt - Fonction auxiliaire pour trouver la racine carrée.
* @n: Le nombre de base.
* @guess: Le nombre que l'on teste actuellement.
*
* Return: La racine carrée naturelle, ou -1 si elle n'existe pas.
*/
int find_sqrt(int n, int guess)
{
	if (guess * guess == n)
	{
		return (guess);
	}

	if (guess * guess > n)
	{
		return (-1);
	}

	return (find_sqrt(n, guess + 1));
}

/**
* _sqrt_recursion - Retourne la racine carrée naturelle d'un nombre.
* @n: Le nombre dont on cherche la racine.
*
* Return: La racine carrée, ou -1 s'il n'y a pas de racine naturelle.
*/
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	return (find_sqrt(n, 1));
}
