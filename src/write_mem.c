/* File:     write_mem.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Implements the write memory function for ECEN 5813: Project 1
 */

#include <stdio.h>
#include "../inc/write_mem.h"

void write_mem(uint32_t ** start_mem, uint32_t ** end_mem, const bool * alloc_status, const char address_arg[16], const char value_arg[16])
{
	long unsigned int address = 0;
	uint32_t * mem_pointer = NULL;
	uint32_t value = 0;

	/* ensure that memory has been allocated */
	if (!*alloc_status)
	{
		printf("Allocate the memory first\n");
		return;
	}

	/* read the first argument (address) */
	if (1 != sscanf(address_arg, "%lx", &address))
	{
		printf("Invalid write address: %s\n", address_arg);
		return;
	}

	/* check if it's the magic address */
	if (address == 0xffffffff) {
		address = (unsigned long int) *start_mem;
	}
	
	/* ensure that the address is within range */
	if (address < (long unsigned int) *start_mem || address > (long unsigned int) *end_mem)
	{
		printf("The write address must be within %#lx - %#lx\n", (long unsigned int) *start_mem, (long unsigned int) *end_mem);
		return;
	}

	/* ensure a word-aligned address */
	if ((address - (long unsigned int) *start_mem) % 4 != 0)
	{
		printf("The address must be word-aligned\n");
		return;
	}

	mem_pointer = (uint32_t *) address;

	/* read the second argument (value) */
	if (1 != sscanf(value_arg, "%x", &value))
	{
		printf("Invalid value: %s\n", value_arg);
		return;
	}

	/* perform the write */
	*mem_pointer = value;

	printf("Wrote %x to %#lx\n", value, (long unsigned int) mem_pointer);
}