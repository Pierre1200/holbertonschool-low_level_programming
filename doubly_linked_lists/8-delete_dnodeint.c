#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: the index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i;

	/* Sécurité : si le pointeur head est NULL ou si la liste est vide */
	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	/* Cas 1 : Suppression du premier nœud (index 0) */
	if (index == 0)
	{
		*head = temp->next; /* La nouvelle tête devient le 2ème nœud */
		if (*head != NULL)  /* Si la liste n'avait pas qu'un seul élément */
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* On avance jusqu'au nœud à supprimer */
	for (i = 0; i < index; i++)
	{
		if (temp == NULL) /* Si on dépasse la taille de la liste */
			return (-1);
		temp = temp->next;
	}

	/* Si le nœud à l'index n'existe pas (ex: index = taille exacte de la liste) */
	if (temp == NULL)
		return (-1);

	/* Cas 2 : Suppression au milieu ou à la fin */
	/* Le 'next' du nœud précédent saute au-dessus de 'temp' */
	temp->prev->next = temp->next;

	/* Si 'temp' n'est pas le dernier nœud, on met à jour le 'prev' du suivant */
	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	free(temp); /* On détruit le nœud isolé */

	return (1);
}
