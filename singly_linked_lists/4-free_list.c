#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a list_t list.
 * @head: A pointer to the head of the list_t list.
 *
 * Return: void.
 */
void free_list(list_t *head)
{
	list_t *temp;

	/* Tant qu'on n'est pas arrivé à la fin de la liste */
	while (head != NULL)
	{
		/* 1. On sauvegarde l'adresse du prochain nœud */
		temp = head->next;

		/* 2. On libère la chaîne de caractères (allouée par strdup) */
		free(head->str);

		/* 3. On libère le nœud lui-même */
		free(head);

		/* 4. On passe au nœud suivant pour le prochain tour de boucle */
		head = temp;
	}
}
