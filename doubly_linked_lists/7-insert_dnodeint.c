#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: the index where the new node should be added (starts at 0)
 * @n: the data for the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	/* Cas 1 : Insertion tout au début */
	if (idx == 0)
		return (add_dnodeint(h, n));

	temp = *h;
	/* On s'arrête un cran AVANT l'index voulu (à idx - 1) */
	for (i = 0; i < idx - 1; i++)
	{
		if (temp == NULL) /* L'index est plus grand que la liste */
			return (NULL);
		temp = temp->next;
	}

	/* Si temp est NULL après la boucle, c'est que l'index était trop grand */
	if (temp == NULL)
		return (NULL);

	/* Cas 2 : Insertion tout à la fin */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* Cas 3 : Insertion au milieu */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	/* On connecte le nouveau nœud à ses voisins */
	new_node->prev = temp;
	new_node->next = temp->next;

	/* On connecte les voisins au nouveau nœud */
	temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}
