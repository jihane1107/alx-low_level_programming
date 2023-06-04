#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len is a function that returns the number of elements in a linked list.
 * @h: pointer to one element on a linked list
 * Return: number of elements defined here by longueur
 * this code is made by: jihane1107.
 */

size_t list_len(const list_t *h)
{
	size_t longueur = 0;

	while (h != NULL)
	{
		h = h->next;
		longueur++;
	}
	return (longueur);
}
