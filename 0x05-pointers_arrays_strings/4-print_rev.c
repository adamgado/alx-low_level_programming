#include "main.h"
/**
 * print_rev - prints string in reverse
 * @s: string
 * return: 0
 */
void print_rev(char *s)
{
	int reverse = 0;
	int o;

	while (*s != '\0')
	{
		reverse++;
		s++;
	}
	s--;
	for (o = reverse; o > 0; o--)
	{
		_putchar(*s);
		s--;
	}

	_putchar('\n');
}
