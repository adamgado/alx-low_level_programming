#include "lists.h"
/**
  * add_dnodeint - add node at start of doubly linked list
  * @head: head of doubly linked list
  * @n: number
  * Return: new head of doubly linked list
  */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = NULL;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	if (*head != NULL)
	{
		new->next = *head;
		new->prev = (*head)->prev;
		(*head)->prev = new;
		*head = new;
		return (*head);
	}
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (*head);
}
