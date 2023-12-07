#include "lists.h"
/**
  * insert_dnodeint_at_index - insert new node at index position
  * @h: head of doubly linked list
  * @idx: index of position
  * @n: number to insert
  * Return: address of new node, or NULL
  */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *current;
	unsigned int a;

	new = NULL;
	if (idx == 0)
	{
		new = add_dnodeint(h, n);
	}
	else
	{
		current = *h;
		a = 1;
		if (current != NULL)
		{
			while (current->prev != NULL)
			{
				current = current->prev;
			}
		}
		while (current != NULL)
		{
			if (a == idx)
			{
				if (current->next == NULL)
				{
					new = add_dnodeint_end(h, n);
				}
				else
				{
					new = malloc(sizeof(dlistint_t));
					if (new != NULL)
					{
						new->n = n;
						new->next = current->next;
						new->prev = current;
						current->next->prev = new;
						current->next = new;
					}
				}
				break;
			}
			current = current->next;
			a++;
		}
	}
	return (new);
}
