#include "function_pointers.h"
#include <stddef.h>

/**
* print_name - Appelle une fonction pour imprimer un nom.
* @name: La chaîne de caractères à imprimer.
* @f: Un pointeur sur fonction qui prend un char* en argument.
*
* Description: Vérifie les pointeurs puis exécute la fonction passée.
*/
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
	{
		f(name);
	}
}
