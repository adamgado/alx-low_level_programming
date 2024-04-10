#include "search_algos.h"
/**
 * jump_search - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located
 */
int jump_search(int *array, size_t size, int value)
{
	size_t x, a, b, prev;

	if (array == NULL || size == 0)
	{
		return (-1);
	}
	a = sqrt((double)size);
	b = 0;
	prev = x = 0;
	while (x < size && array[x] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", x, array[x]);
		if (array[x] == value)
		{
			return (x);
		}
		b++;
		prev = x;
		x = a * b;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", prev, x);
	for (; prev <= x && prev < size; prev++)
	{
		printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
		{
			return (prev);
		}
	}
	return (-1);
}
