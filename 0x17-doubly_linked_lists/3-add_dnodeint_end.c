#include "lists.h"
/**
  * add_dnodeint_end - add node at end of doubly linked list
  * @head: The head of the doubly linked list
  * @n: The number to place in the new node
  * Return: The new head of the doubly linked list
  */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *current = NULL, *new = NULL;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	if (*head)
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		new->next = NULL;
		new->prev = current;
		current->next = new;
		return (new);
	}
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}
