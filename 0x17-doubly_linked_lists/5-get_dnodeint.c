#include "lists.h"
/**
 * get_dnodeint_at_index - get node from doubly linked list
 * @head: head of doubly linked list
 * @index: index to find
 * Return: specific node of doubly linked list
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int a = 0;

	while (current != NULL)
	{
		if (a == index)
		{
			return (current);
		}
		current = current->next;
		a++;
	}
	return (NULL);
}
