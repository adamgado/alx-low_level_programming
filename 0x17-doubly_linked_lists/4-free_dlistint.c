#include "lists.h"
/**
  * free_dlistint - free doubly linked list
  * @head: head of doubly linked list
  */
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
	{
		return;
	}
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head)
}
