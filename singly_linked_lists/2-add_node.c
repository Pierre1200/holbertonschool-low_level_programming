#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a list_t list.
 * @head: A double pointer to the head of the list_t list.
 * @str: The string to be added to the list_t node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	unsigned int length = 0;

	/* 1. Calculer la longueur de la chaîne str */
	while (str[length])
		length++;

	/* 2. Allouer de la mémoire pour le nouveau nœud */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* 3. Remplir les données du nœud */
	new_node->str = strdup(str);
	new_node->len = length;

	/* 4. Connecter le nouveau nœud au reste de la liste */
	new_node->next = (*head);

	/* 5. Faire pointer la tête de la liste sur ce nouveau nœud */
	(*head) = new_node;

	return (*head);
}
