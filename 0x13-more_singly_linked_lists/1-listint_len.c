#include <stdio.h>
#include "lists.h"


/**
 * listint_len - function that calculate number of elements of list.
 * @h: a pointer to the head of alist.
 * Return: the number of elements
 */

size_t listint_len(const listint_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		h = h->next;
		i++;
	}
	return (i);
}
