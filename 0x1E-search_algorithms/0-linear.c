#include "search_algos.h"
/**
 * linear_search - searches for a value in an array of integers
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located
 */
int linear_search(int *array, size_t size, int value)
{
	size_t a = 0;

	if (array == NULL)
	{
		return (-1);
	}
	for (a = 0; a < size; a++)
	{
		printf("Value checked array[%lu] = [%d]\n", a, array[a]);
		if (value == array[a])
		{
			return (a);
		}
	}
	return (-1);
}
