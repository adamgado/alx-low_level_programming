#include "main.h"
/**
 * binary_to_uint - convert binary to unsigned
 * @b: string containing binary number
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int unint = 0;

	if (!b)
		return (0);

	for (a = 0; b[a]; a++)
	{
		if (b[a] < '0' || b[a] > '1')
			return (0);
		unint = 2 * unint + (b[a] - '0');
	}

	return (unint);
}

