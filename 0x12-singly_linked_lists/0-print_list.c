#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_list - function that prints all the elements of a list_t.
 * @h: pointer to the list.
 *
 * if h->str is NULL print [0] (nil).
 * You are allowed to use printf.
 * Return: the number of nodes.
 * @return count
 */
typedef struct node {
     int data;
     struct node* next;
}node_t;
 
size_t print_list(const list_t* h){
if (!h)
        {
	printf("[%d] %s\n", 0, "(nil)");
	}
 
const list_t* current = h;
size_t count=1;
    
while (current->next!=NULL){
        printf("%d ", current->data);
        ++count;
        current = current->next;
    }
printf("%d\n", current->data);
return count + print_list(current->next);
}
