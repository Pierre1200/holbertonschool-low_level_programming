#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the doubly linked list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	/* On parcourt la liste jusqu'à la fin */
	while (head != NULL)
	{
		temp = head;       /* 1. On sauvegarde l'adresse du nœud actuel */
		head = head->next; /* 2. On avance le pointeur principal au nœud suivant */
		free(temp);        /* 3. On détruit l'ancien nœud en toute sécurité */
	}
}
