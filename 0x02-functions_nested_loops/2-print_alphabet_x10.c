#include "main.h"

/**
 * print_alphabet_x10 - Prints 10 times the alphabet, in lowercases
 * Code by jihane1107
*/

void print_alphabet_x10(void)
{
	int i = 0;
	char letter;

	while (i++ <= 9)
	{
		for (letter = 'a'; letter <= 'z'; letter++)
			_putchar(letter);
		_putchar('\n');
	}
}
