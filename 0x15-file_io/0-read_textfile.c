#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: character.
 * @letters: size.
 *
 * Return: numbers of letters, 0 if error.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fil;
	ssize_t lire, ecr;
	char *b;

	if (!filename)
		return (0);

	fil = open(filename, O_RDONLY);

	if (fil == -1)
		return (0);

	b = malloc(sizeof(char) * (letters));
	if (!b)
		return (0);

	lire = read(fil, b, letters);
	ecr = write(STDOUT_FILENO, b, lire);

	close(fil);

	free(b);

	return (ecr);
}
