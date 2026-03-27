#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: A double pointer to the head of the list_t list.
 * @str: The string to be added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *temp;
	unsigned int length = 0;

	/* 1. Calcul de la longueur de la chaîne */
	while (str && str[length])
		length++;

	/* 2. Allocation de la mémoire pour le nouveau nœud */
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	/* 3. Initialisation du nouveau nœud */
	new_node->str = strdup(str);
	if (new_node->str == NULL) /* Sécurité si strdup échoue */
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = length;
	new_node->next = NULL; /* Il sera le dernier, donc pointe vers NULL */

	/* 4. Cas spécial : la liste est vide */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	/* 5. Parcours de la liste pour trouver le dernier nœud */
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	/* 6. On a trouvé le dernier, on y accroche notre nouveau nœud */
	temp->next = new_node;
	return (new_node);
}
