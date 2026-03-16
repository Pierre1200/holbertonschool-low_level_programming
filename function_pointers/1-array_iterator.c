#include "function_pointers.h"
#include <stddef.h>

/**
 * array_iterator - Exécute une fonction sur chaque élément d'un tableau.
 * @array: Le tableau d'entiers.
 * @size: La taille du tableau.
 * @action: Le pointeur vers la fonction à exécuter.
 *
 * Return: Rien.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
size_t i;

	if (array != NULL && action != NULL)
	{
	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
	}
}
