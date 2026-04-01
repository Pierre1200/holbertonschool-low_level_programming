#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table you want to add or update the key/value to
 * @key: the key (cannot be an empty string)
 * @value: the value associated with the key (must be duplicated)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node, *temp;
	char *value_copy;
	/* 1. Sécurité : vérifier que les param sont valides */
	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	/* On duplique la valeur tout de suite */
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);
	/* 2. Récupérer l'index où ranger notre donnée */
	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	/* 3. Vérifier si la clé existe DÉJÀ */
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			/* on met à jour la valeur et on libère */
			free(temp->value);
			temp->value = value_copy;
			return (1);
		}
		temp = temp->next;
	}
	/* 4. Si la clé n'existe pas, nouveau nœud */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(value_copy);
		return (0);
	}

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		free(value_copy);
		return (0);
	}
	new_node->value = value_copy;
	/* 5. On l'insère au DÉBUT (gestion des collisions) */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
