#include "lists.h"
/**
  * dlistint_len - count number of elements in doubly linked list
  * @h: doubly linked list
  * Return: number of elements in doubly linked list
  */
size_t dlistint_len(const dlistint_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}
