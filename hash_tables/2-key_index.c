#include "hash_tables.h"

/**
 * key_index - gives you the index of a key
 * @key: the key (string) to hash
 * @size: the size of the array of the hash table
 *
 * Return: the index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/* 1. On calcule le hash géant avec la fonction de la tâche précédente */
	unsigned long int hash_value = hash_djb2(key);

	/* 2. On utilise le modulo pour réduire ce nombre à la taille du tableau */
	return (hash_value % size);
}
