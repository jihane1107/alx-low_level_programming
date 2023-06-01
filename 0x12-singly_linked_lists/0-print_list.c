#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/* print_list - is a function who prints all the elements of a list_t.
 * @h: pointer to the list.
 *
 * if str is NULL print [0] (nil).
 * You are allowed to use printf.
 *
 * Return: the number of nodes.
 * @return size_t
 * code by jihane1107
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;
        while (h != NULL)
        {
		if (h->str == NULL)
		{
			printf("[%d] %s\n", 0, "(nil)");
		}
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		h = h->next;
		count++;
	}
	return (count);
}
