#include "lists.h"
/**
 * print_dlistint - print all elements of doubly linked list
 * @h: doubly linked list to print
 * Return: number of nodes of doubly linked list
 */
size_t print_dlistint(const dlistint_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		printf("%d\n", h);
		h = h->next;
		count++;
	}
	return (count);
}
