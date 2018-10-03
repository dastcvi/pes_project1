/* File:     free_mem.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Implements the free memory function for ECEN 5813: Project 1
 */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/free_mem.h"

void free_mem(uint32_t ** mem_pointer, bool * alloc_status)
{
	long unsigned int address = 0;

	/* ensure that memory has been allocated */
	if (!*alloc_status)
	{
		printf("No allocated memory to free\n");
		return;
	}

	/* ensure that we don't have a null pointer */
	if (*mem_pointer == NULL)
	{
		printf("Error: NULL global memory pointer\n");
		return;
	}

	/* deallocate the memory */
	address = (long unsigned int) *mem_pointer;
	free(*mem_pointer);
	*alloc_status = false;

	printf("Freed previously allocated memory at %#lx\n", address);
}