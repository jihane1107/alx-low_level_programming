#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: pointer to char.
 * @text_content: pointer to char.
 *
 * Return: 1 if here -1 if file not here
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fil;
	int nbr;
	int lirec;

	if (!filename)
		return (-1);

	fil = open(filename, O_WRONLY | O_APPEND);

	if (fil == -1)
		return (-1);

	if (text_content)
	{
		for (nbr = 0; text_content[nbr]; nbr++)
			;

		lirec = write(fil, text_content, nbr);

		if (lirec == -1)
			return (-1);
	}

	close(fil);

	return (1);
}
