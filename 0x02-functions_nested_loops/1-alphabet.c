#include "main.h"

/**
 * print_alphabet - print the alphabet in lowercase, followed by a new line.
 * Code by jihane1107
*/

void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		_putchar(letter);

	putchar('\n');
}
