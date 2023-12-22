#include "hash_tables.h"
/**
 * hash_table_print - print hash table
 * @ht: pointer to hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int a;
	hash_node_t *current;
	char comma_var = 0;

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	for (a = 0; a < ht->size; a++)
	{
		current = ht->array[a];
		while (current)
		{
			if (comma_var == 1)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
			comma_var = 1;
			current = current->next;
		}
	}
	printf("}\n");
}
