/* File:     alloc_mem.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Implements the allocate memory function for ECEN 5813: Project 1
 */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/alloc_mem.h"

void alloc_mem(uint32_t ** mem_start, uint32_t ** mem_end, bool * alloc_status, const char num_words[16])
{
	int alloc_size = 0;

	/* check if memory has already been allocated */
	if (*alloc_status)
	{
		printf("Memory already allocated\n");
		return;
	}

	/* read the first argument (allocation size) */
	if (1 != sscanf(num_words, "%d", &alloc_size))
	{
		printf("Invalid number of words to allocate: %s\n", num_words);
		return;
	}
	
	/* verify that the address is within bounds */
	if (1 > alloc_size || MAX_ALLOC_WORDS < alloc_size)
	{
		printf("Alloc size must be between 1 and %d words\n", MAX_ALLOC_WORDS);
		return;
	}

	/* perform the allocation, and note the start and end word pointers */
	*mem_start = (uint32_t *) malloc(alloc_size*4);
	*mem_end = &((*mem_start)[alloc_size-1]);

	/* verify the allocation */
	if (*mem_start != NULL)
	{
		*alloc_status = true;
		printf("Allocated %d words at address %#lx\n", alloc_size, (long unsigned int) *mem_start);
		printf("The highest valid write address is %#lx\n", (long unsigned int) *mem_end);
	}
	else
	{
		*alloc_status = false;
		printf("Malloc error, memory unallocated\n");
	}
}