/* File:     write_mem.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Implements the write memory function for ECEN 5813: Project 1
 */

#include <stdio.h>
#include "../inc/write_mem.h"

void write_mem(char args[4][16], uint32_t ** mem_start, uint32_t ** mem_end, uint32_t * seed, bool * alloc_status)
{
	long unsigned int address = 0;
	uint32_t * mem_pointer = NULL;
	uint32_t value = 0;

	/* avoid unused parameter warnings caused by needing standard function prototype */
	(void)(seed);

	/* ensure that memory has been allocated */
	if (!*alloc_status)
	{
		printf("Allocate the memory first\n");
		return;
	}

	/* read the first argument (address) */
	if (1 != sscanf(args[1], "%lx", &address))
	{
		printf("Invalid write address: %s\n", args[1]);
		return;
	}

	/* check if it's the magic address */
	if (address == 0xffffffff) {
		address = (unsigned long int) *mem_start;
	}
	
	/* ensure that the address is within range */
	if (address < (long unsigned int) *mem_start || address > (long unsigned int) *mem_end)
	{
		printf("The write address must be within %#lx - %#lx\n", (long unsigned int) *mem_start, (long unsigned int) *mem_end);
		return;
	}

	/* ensure a word-aligned address */
	if ((address - (long unsigned int) *mem_start) % 4 != 0)
	{
		printf("The address must be word-aligned\n");
		return;
	}

	mem_pointer = (uint32_t *) address;

	/* read the second argument (value) */
	if (1 != sscanf(args[2], "%x", &value))
	{
		printf("Invalid value: %s\n", args[2]);
		return;
	}

	/* perform the write */
	*mem_pointer = value;

	printf("Wrote %x to %#lx\n", value, (long unsigned int) mem_pointer);
}