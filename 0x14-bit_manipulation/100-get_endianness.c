#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big, 1 if little
 */
int get_endianness(void)
{
	unsigned int d;
	char *car;

	d = 1;
	car = (char *) &d;

	return ((int)*car);
}
