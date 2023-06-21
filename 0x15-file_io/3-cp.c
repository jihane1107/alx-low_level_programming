#include "main.h"
#include <stdio.h>

/**
 * error_file - checks we can open a file
 * @file_from: integer
 * @file_to: integer
 * @argv: argument.
 * Return: none.
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check the code
 * @argc: number of arguments.
 * @argv: vecteur argument
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, err;
	ssize_t nc, nec;
	char b[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_from, file_to, argv);

	nc = 1024;
	while (nc == 1024)
	{
		nc = read(file_from, b, 1024);
		if (nc == -1)
			error_file(-1, 0, argv);
		nec = write(file_to, b, nc);
		if (nec == -1)
			error_file(0, -1, argv);
	}

	err = close(file_from);
	if (err == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
