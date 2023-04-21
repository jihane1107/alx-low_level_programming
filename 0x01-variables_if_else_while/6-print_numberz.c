#include <stdio.h>
/**
 * main - main block
 * Description: prints all single digit numbers of base zero
 * starting from zero, followed by a new line.
 * Return: zero
 */
int main(void)
{
	int c = 0;

	while (c < 10)
	{
		putchar(48 + c);
		c++;
	}

	putchar('\n');
	return (0);
}
