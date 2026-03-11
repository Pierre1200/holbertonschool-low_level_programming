#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints all the details of a struct dog
 * @d: Pointer to the struct dog to print
 *
 * Description: Safely prints the dog's name, age, and owner.
 * If a string pointer is NULL, it prints (nil) instead.
 * If the struct pointer is NULL, it prints nothing.
 */

void print_dog(struct dog *d)
{
	/* Si le pointeur principal est NULL, on ne fait rien */
	if (d == NULL)
		return;

	/* Affichage du Nom */
	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	/* Affichage de l'Âge */
	printf("Age: %f\n", d->age);

	/* Affichage du Propriétaire */
	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}
