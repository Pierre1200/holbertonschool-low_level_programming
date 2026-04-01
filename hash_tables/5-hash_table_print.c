#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table to print
 *
 * Description: Prints the key/value pairs in the order
 * they appear in the array of the hash table.
 * Format: {'key': 'value', 'key2': 'value2'}
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	unsigned char comma_flag = 0; /* 0 = pas de virgule, 1 = mettre une virgule */

	/* 1. Sécurité : si la table est NULL */
	if (ht == NULL)
		return;

	printf("{");

	/* 2. On parcourt chaque case du tableau */
	for (i = 0; i < ht->size; i++)
	{
		/* Si la case n'est pas vide, on parcourt sa liste chaînée */
		if (ht->array[i] != NULL)
		{
			node = ht->array[i];
			while (node != NULL)
			{
				/* Si ce n'est pas le premier élément imprimé, on met une virgule */
				if (comma_flag == 1)
					printf(", ");

				/* On imprime la clé et la valeur au format Python */
				printf("'%s': '%s'", node->key, node->value);

				/* On active le drapeau pour les prochains éléments */
				comma_flag = 1;

				/* On passe au nœud suivant en cas de collision */
				node = node->next;
			}
		}
	}

	printf("}\n");
}
