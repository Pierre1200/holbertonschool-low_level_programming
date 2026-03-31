#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: double pointer to the head of the list
 * @n: the integer to add to the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *temp;

	/* On vérifie que le pointeur sur la tête n'est pas invalide */
	if (head == NULL)
		return (NULL);

	/* 1. Création et initialisation du nouveau nœud */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL; /* Puisqu'il sera à la fin, son suivant est NULL */

	/* 2. Cas particulier : la liste est vide */
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/* 3. Parcourir la liste pour trouver le dernier nœud */
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	/* 4. On accroche le nouveau nœud au dernier nœud trouvé */
	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}
