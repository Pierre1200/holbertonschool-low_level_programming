#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: double pointer to the head of the list
 * @n: the integer to add to the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	/* On vérifie que le pointeur head n'est pas invalide */
	if (head == NULL)
		return (NULL);

	/* 1. Allocation de la mémoire pour le nouveau nœud */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	/* 2. Initialisation des valeurs du nouveau nœud */
	new_node->n = n;
	new_node->prev = NULL;    /* 1er nœud, il n'a pas de précédent */
	new_node->next = *head;   /* Son suivant est l'ancienne tête de liste */

	/* 3. Mise à jour de l'ancienne tête (si la liste n'était pas vide) */
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}

	/* 4. Le pointeur principal head pointe maintenant sur notre nouveau nœud */
	*head = new_node;

	return (new_node);
}
