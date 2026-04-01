#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table you want to look into
 * @key: the key you are looking for
 *
 * Return: the value associated with the element,
 * or NULL if key couldn't be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	/* 1. Sécurité : vérifier que les paramètres sont valides */
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	/* 2. Calculer l'index correspondant à la clé */
	index = key_index((const unsigned char *)key, ht->size);

	/* 3. Se placer au début de la liste chaînée à cet index */
	node = ht->array[index];

	/* 4. Parcourir la liste pour trouver la clé exacte */
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			/* Clé trouvée : on retourne sa valeur */
			return (node->value);
		}
		node = node->next;
	}

	/* 5. Si on sort de la boucle, la clé n'existe pas dans la table */
	return (NULL);
}
