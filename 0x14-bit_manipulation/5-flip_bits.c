#include "main.h"

/**
 * flip_bits - returns the number of bits needed
 * to flip to get from one number to another
 * @n: unsigned first number.
 * @m: unsigned second number.
 *
 * Return: the number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int num;

	for (num = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			num++;
	}

	return (num);
}
