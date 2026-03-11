#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees memory allocated for a dog
 * @d: Pointer to the dog to free
 *
 * Description: Frees the dynamically allocated strings for name
 * and owner, and then frees the struct itself.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);

	free(d);
}
