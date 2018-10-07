/* File:     free_mem.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Implements the free memory function for ECEN 5813: Project 1
 */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/free_mem.h"

void free_mem(char args[4][16], uint32_t ** mem_start, uint32_t ** mem_end, uint32_t * seed, bool * alloc_status)
{
	long unsigned int address = 0;

	/* avoid unused parameter warnings caused by needing standard function prototype */
	(void)(args);
	(void)(mem_end);
	(void)(seed);

	/* ensure that memory has been allocated */
	if (!*alloc_status)
	{
		printf("No allocated memory to free\n");
		return;
	}

	/* ensure that we don't have a null pointer */
	if (*mem_start == NULL)
	{
		printf("Error: NULL global memory pointer\n");
		return;
	}

	/* deallocate the memory */
	address = (long unsigned int) *mem_start;
	free(*mem_start);
	*alloc_status = false;

	printf("Freed previously allocated memory at %#lx\n", address);
}