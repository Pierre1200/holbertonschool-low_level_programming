#include "hash_tables.h"
#include <stdlib.h>

/**
* hash_table_delete - deletes a hash table
* @ht: the hash table to delete
*/
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;

	hash_node_t *node, *temp;

	/* 1. Sécurité : vérifier que la table existe */
	if (ht == NULL)
		return;

	/* 2. Parcourir chaque case du tableau */
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];

		/* 3. Parcourir et libérer la liste chaînée à cet index */
		while (node != NULL)
		{
			/* On sauvegarde le noeud suivant avant de détruire l'actuel */
			temp = node->next;

			/* On libère le contenu du noeud (car on a utilisé strdup) */
			free(node->key);
			free(node->value);

			/* On libère le noeud lui-même */
			free(node);

			/* On passe au suivant */
			node = temp;
		}
	}

	/* 4. Libérer le tableau de pointeurs */
	free(ht->array);

	/* 5. Libérer la structure principale */
	free(ht);
}
