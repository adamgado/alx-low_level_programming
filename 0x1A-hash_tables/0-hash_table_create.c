#include "hash_tables.h"
/**
 * hash_table_create - create hash table
 * @size: size of the array
 * Return: a pointer to the new table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;
	unsigned long int a;

	new_table = malloc(sizeof(hash_table_t));
	if (new_table == NULL)
	{
		return (NULL);
	}
	new_table->size = size;
	new_table->array = malloc(size * sizeof(hash_node_t *));
	if (new_table->array == NULL)
	{
		free(new_table);
		return (NULL);
	}
	for (a = 0; a < size; a++)
	{
		new_table->array[a] = NULL;
	}
	return (new_table);
}
