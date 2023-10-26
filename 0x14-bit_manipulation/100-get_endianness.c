#include "main.h"
/**
 * get_endianness - check if machine is little or big endian
 * Return: 0 big, 1 little
 */
int get_endianness(void)
{
	unsigned int a = 1;
	char *c = (char *) &a;

	return (*c);
}
