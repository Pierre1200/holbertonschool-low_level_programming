#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table,
 * or NULL if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	/* 1. Allocation de la mémoire pour la structure de base */
	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	/* 2. Initialisation de la taille */
	ht->size = size;

	/* 3. Allocation de la mémoire pour le tableau (array) */
	/* Le tableau contient des pointeurs vers des hash_node_t */
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
	{
		/* Si l'allocation du tableau échoue, on libère la structure d'avant */
		free(ht);
		return (NULL);
	}

	/* 4. Initialisation de toutes les cases du tableau à NULL */
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}
