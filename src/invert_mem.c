/* File:     invert_mem.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Implements the invert memory function for ECEN 5813: Project 1
 */

#include <sys/time.h>
#include <stdio.h>
#include "../inc/invert_mem.h"

void invert_mem(uint32_t ** start_mem, uint32_t ** end_mem, const bool * alloc_status, const char address_arg[16], const char num_words_arg[16])
{
	long unsigned int address = 0;
	uint32_t * mem_pointer = NULL;
	uint32_t num_words = 0;

	if (!*alloc_status)
	{
		printf("Allocate the memory first\n");
		return;
	}

	if (1 != sscanf(address_arg, "%lx", &address))
	{
		printf("Invalid start address: %s\n", address_arg);
		return;
	}

	if (address < (long unsigned int) *start_mem || address > (long unsigned int) *end_mem)
	{
		printf("The start address must be within %#lx - %#lx\n", (long unsigned int) *start_mem, (long unsigned int) *end_mem);
		return;
	}

	if ((address - (long unsigned int) *start_mem) % 4 != 0)
	{
		printf("The start address must be word-aligned\n");
		return;
	}

	if (1 != sscanf(num_words_arg, "%u", &num_words))
	{
		printf("Invalid number of words: %s\n", num_words_arg);
		return;
	}

	if (((unsigned long int) (*start_mem) + (num_words - 1) * 4) > (unsigned long int) (*end_mem))
	{
		printf("Invert range extends beyond allocated memory\n");
		return;
	}

	mem_pointer = (uint32_t *) address;

	uint32_t itr = 0;

	struct timeval start, end;
	gettimeofday(&start,NULL);
	
	for (itr = 0; itr < num_words; itr++)
	{
		mem_pointer[itr] ^= 0xFFFFFFFF;
	}
	
	gettimeofday(&end,NULL);

	unsigned long int micros_elapsed = 1000000 * end.tv_sec + end.tv_usec - (1000000 * start.tv_sec + start.tv_usec);

	printf("Inverted memory from %#lx to %#lx in %lu us\n", address, address + 4*(num_words-1), micros_elapsed);
}