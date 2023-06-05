#include <stdio.h>
#include "lists.h"


/**
 * print_listint - function that prints elements of list.
 * @h: a pointer to the head of alist.
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}
