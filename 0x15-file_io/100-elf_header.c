#include "main.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * main - checks if the code is correct
 * description : shows info at the ELF header in the begin of an ELF file
 * @argc: number ofarg
 * @argv: array of arg
 * Return: 0 if correct and 98 if error
 */
int main(int argc, char *argv[])
{
	int fil;
	Elfheader *header;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);

	fil = open(argv[1], O_RDONLY);
	if (fil == -1)
		dprintf(STDERR_FILENO, "Error! program can’t open file %s\n", argv[1]), exit(98);

	header = malloc(sizeof(Elfheader));
	if (header == NULL)
		dprintf(STDERR_FILENO, "Error! allocation incorrect\n"), exit(98);
	if (read(fil, header, sizeof(Elfheader)) != sizeof(Elfheader))
		dprintf(STDERR_FILENO, "Error! program can't read file %s\n", argv[1]), exit(98);

	/* this code checks if the file is an ELF */
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
	    header->e_ident[EI_MAG1] != ELFMAG1 ||
	    header->e_ident[EI_MAG2] != ELFMAG2 ||
	    header->e_ident[EI_MAG3] != ELFMAG3)
		dprintf(STDERR_FILENO, "Error! this is not an ELF\n"), exit(98);

	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x\n",
	       header->e_ident[EI_MAG0], header->e_ident[EI_MAG1],
	       header->e_ident[EI_MAG2], header->e_ident[EI_MAG3]);
	printf("  Class:                             %s\n",
		   	       header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
		   	       header->e_ident[EI_DATA] == ELFILATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
		   	       header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "UNIX - System V");
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
		   	       header->e_type == ET_EXEC ? "EXEC (Executable file)" : "EXEC (Executable file)");
	printf("  Point address:               0x%lx (bytes into file)\n", header->e_entry);
	printf("  Start of program headers:          %d (bytes into file)\n", header->e_phoff);
	printf("  Start of section headers:          %d (bytes into file)\n", header->e_shoff);
	printf("  Flags:                             0x%x\n", header->e_flags);
	printf("  Size of header:               %d (bytes)\n", header->e_ehsize);
	printf("  Size of program headers:           %d (bytes)\n", header->e_phentsize);
	printf("  Number of program headers:         %d\n", header->e_phnum);
	printf("  Size of section headers:           %d (bytes)\n", header->e_shentsize);
	printf("  Number of section headers:         %d\n", header->e_shnum);
	printf("  Section header str tabl and index: %d\n", header->e_shstrndx);

	/* this code closes the ELF file */
	if (close(fil) == -1)
		dprintf(STDERR_FILENO, "Error! Program can't close fil %d\n", fil), exit(98);

	return (0);
}
