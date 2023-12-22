#include "hash_tables.h"
/**
 * hash_table_set - add element to hash table
 * @ht: pointer to hash table
 * @key: key to add
 * @value: value to add
 * Return: 1 on success, 0 on fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx = 0;
	char *value_tmp;
	char *key_tmp;
	hash_node_t *current;
	hash_node_t *new_node;

	if (!ht || !key || !*key || !value)
		return (0);

	value_tmp = strdup(value);
	if (!value_tmp)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
	current = ht->array[idx];

	while (current)
	{
		if (!strcmp(key, current->key))
		{
			free(current->value);
			current->value = value_tmp;
			return (1);
		}
		current = current->next;
	}
	new_node = calloc(1, sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(value_tmp);
		return (0);
	}
	key_tmp = strdup(key);
	if (!key_tmp)
		return (0);
	new_node->key = key_tmp;
	new_node->value = value_tmp;
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;
	return (1);
}
