#include "lists.h"
/**
  * sum_dlistint - sum of all data in doubly linked list
  * @head: head of doubly linked list
  * Return: sum of data
  */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	int sum = 0;

	while (current != NULL)
	{
		sum = sum + current->n;
		current = current->next;
	}
	return (sum);
}
