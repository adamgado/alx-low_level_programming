#include "main.h"
/**
 * print_binary - prints binary conversion of decimal
 * @n: number to convert
 */
void print_binary(unsigned long int n)
{
	int a, count = 0;
	unsigned long int current_bit;

	for (a = 63; a >= 0; a--)
	{
		current_bit = n >> a;

		if (current_bit & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
