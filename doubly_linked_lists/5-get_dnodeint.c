#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: the index of the node, starting from 0
 *
 * Return: the nth node, or NULL if the node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	/* On parcourt la liste tant qu'on n'est pas à la fin */
	while (head != NULL)
	{
		/* Si notre compteur correspond à l'index recherché, on a trouvé ! */
		if (count == index)
			return (head);

		head = head->next; /* On avance d'un pas */
		count++;           /* On incrémente notre compteur */
	}

	/* Si la boucle se termine, ça veut dire que l'index est trop grand */
	return (NULL);
}
