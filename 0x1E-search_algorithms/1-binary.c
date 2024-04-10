#include "search_algos.h"
/**
 * binary_search - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located
 */
int binary_search(int *array, size_t size, int value)
{
	size_t a, left, right;

	if (array == NULL)
	{
		return (-1);
	}
	for (left = 0, right = size - 1; right >= left;)
	{
		printf("Searching in array: ");
		for (a = left; a < right; a++)
		{
			printf("%d, ", array[a]);
		}
		printf("%d\n", array[a]);
		a = left + (right - left) / 2;
		if (array[a] == value)
		{
			return (a);
		}
		if (array[a] > value)
		{
			right = a - 1;
		}
		else
		{
			left = a + 1;
		}
	}
	return (-1);
}
