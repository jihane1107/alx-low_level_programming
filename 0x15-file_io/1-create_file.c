#include "main.h"

/**
 * create_file - creates file
 * @filename: character pointer.
 * @text_content: character pointer.
 *
 * Return: 1 if correct, -1 if error.
 */
int create_file(const char *filename, char *text_content)
{
	int fil;
	int nbr;
	int lirec;

	if (!filename)
		return (-1);

	fil = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fil == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nbr = 0; text_content[nbr]; nbr++)
		;

	lirec = write(fil, text_content, nbr);

	if (lirec == -1)
		return (-1);

	close(fil);

	return (1);
}
