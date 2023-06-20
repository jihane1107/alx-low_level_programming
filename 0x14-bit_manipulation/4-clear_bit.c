#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: pointer from 0 to bit.
 * @index: unsigned int.
 *
 * Return: 1 if correct, -1 if error.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int u;

	if (index > 63)
		return (-1);

	u = 1 << index;

	if (*n & u)
		*n ^= u;

	return (1);
}
