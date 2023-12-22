#include "hash_tables.h"
/**
  * hash_table_get - get value of key in hash table
  * @ht: hash table
  * @key: key
  * Return: value of the key
  */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int x = 0;
	hash_node_t *current;

	if (ht == NULL || key == NULL)
		return (NULL);

	x = key_index((unsigned char *) key, ht->size);
	current = ht->array[x];

	if (current == NULL)
		return (NULL);

	while (strcmp(key, current->key) != 0)
		current = current->next;

	return (current->value);
}
