#include "main.h"

/**
 * binary_to_uint – function that converts a binary number to an unsigned int
 * Return: unsigned int.
 * @b : a binary
 *
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int j;
	int longeur, sec;

	if (!b)
		return (0);

	j = 0;

	for (longeur = 0; b[longeur] != '\0'; longeur++)

	for (longeur--, sec = 1; longeur >= 0; longeur--, sec *= 2)
	{
		if (b[longeur] != '0' && b[longeur] != '1')
		{
			return (0);
		}

		if (b[longeur] & 1)
		{
			j += sec;
		}
	}

	return (j);
}
