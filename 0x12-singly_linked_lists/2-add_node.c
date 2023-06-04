#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lists.h"

/**
 * add_node is a function that adds a new node at the beginning of list.
 * @head: is a pointer on a singly linked list.
 * @str: is s pointer.
 * Return: if it’s correct it returns new address although NULL.
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *nvnode;
	size_t longueur = 0;

	nvnode = malloc(sizeof(list_t));
	if (nvnode == NULL)
		return (NULL);
	while (str[longueur])
		longueur++;
	nvnode->len = longueur;
	nvnode->str = strdup(str);
	nvnode->next = *head;
	*head = nvnode;
	return (nvnode);
}
