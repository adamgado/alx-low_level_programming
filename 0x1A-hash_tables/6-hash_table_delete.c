#include "hash_tables.h"
/**
 * hash_table_delete - delete hash table.
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int a;
	hash_node_t next_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (a = 0; a < ht->size; a++)
	{
		while (ht->array[a] != NULL)
		{
			next_node = ht->array[a]->next;
			free(ht->array[a]->key);
			free(ht->array[a]->value);
			free(ht->array[a]);
			ht->array[a] = next_node;
		}
	}
	free(ht->array);
	ht->array == NULL;
	ht->size == 0;
	free(ht);
}
