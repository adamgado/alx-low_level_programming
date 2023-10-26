#include "main.h"
/**
 * set_bit - set bit at index to 1
 * @n: pointer to number
 * @index: index of bit
 * Return: 1 on success, -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
