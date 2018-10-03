/* File:     help_mem.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Implements help function for ECEN 5813: Project 1
 */

#include <stdio.h>
#include "../inc/help_mem.h"

void help_mem(void)
{
	printf("\n----------------------------------------------------------\n");
	printf("-                   Command Directory                    -\n");
	printf("----------------------------------------------------------\n");
	printf(" all commands are of the form: cmd arg1 arg2 arg3\n");
	printf("----------------------------------------------------------\n");
	printf(" alloc   - allocate a block of memory\n");
	printf("         arg1: number of blocks to allocate (decimal)\n");
	printf(" display - displays memory contents\n");
	printf("         arg1: start address (hex)\n");
	printf("         arg2: number of words to show\n");
	printf(" free    - frees the previously allocated memory\n");
	printf(" help    - displays command directory\n");
	printf(" invert  - inverts all bits in a given section of memory\n");
	printf("         arg1: start address (hex)\n");
	printf("         arg2: number of words to invert\n");
	printf(" pattern - write a pseudo-random pattern to memory\n");
	printf("         arg1: start address (hex)\n");
	printf("         arg2: number of bytes\n");
	printf("         arg3: number generator seed (32-bit unsigned, dec)\n");
	printf(" verify  - verify the randomly generated pattern in memory\n");
	printf("         arg1: start address (hex)\n");
	printf("         arg2: number of words to verify\n");
	printf(" write   - write a given byte of memory\n");
	printf("         arg1: the address (hex)\n");
	printf("         arg2: the value (hex)\n");
	printf(" exit    - exits the program\n");
	printf("----------------------------------------------------------\n\n");
}