/* File:     verify_pattern.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Implements the verify pattern function for ECEN 5813: Project 1
 */

#include <sys/time.h>
#include <stdio.h>
#include "../inc/verify_pattern.h"

/* A linear congruential generator is used as is described in the following
 * Wikipedia article:
 * 
 * https://en.wikipedia.org/wiki/Linear_congruential_generator
 *
 * I have elected to use the parameters used in glibc
 */
uint32_t check_prng(uint32_t current)
{
	uint64_t result = (A_PRNG * current + C_PRNG) % M_PRNG;
	return (uint32_t) (result & 0xffffffff);
}

void verify_pattern(char args[4][16], uint32_t ** mem_start, uint32_t ** mem_end, uint32_t * seed, bool * alloc_status)
{
	long unsigned int address = 0;
	uint32_t * mem_pointer = NULL;
	uint32_t num_words = 0;

	/* ensure that memory has been allocate */
	if (!*alloc_status)
	{
		printf("Allocate the memory first\n");
		return;
	}

	/* read the first argument (address) */
	if (1 != sscanf(args[1], "%lx", &address))
	{
		printf("Invalid start address: %s\n", args[1]);
		return;
	}

	/* check if it's the magic address */
	if (address == 0xffffffff) {
		address = (unsigned long int) *mem_start;
	}

	/* check that the address is in the allocated area */
	if (address < (long unsigned int) *mem_start || address > (long unsigned int) *mem_end)
	{
		printf("The start address must be within %#lx - %#lx\n", (long unsigned int) *mem_start, (long unsigned int) *mem_end);
		return;
	}

	/* ensure a word-aligned address */
	if ((address - (long unsigned int) *mem_start) % 4 != 0)
	{
		printf("The start address must be word-aligned\n");
		return;
	}

	/* read the second argument (number of words to verify) */
	if (1 != sscanf(args[2], "%u", &num_words))
	{
		printf("Invalid number of words: %s\n", args[2]);
		return;
	}

	/* ensure the range won't extend past allocated memory */
	if (((unsigned long int) (*mem_start) + (num_words - 1) * 4) > (unsigned long int) (*mem_end))
	{
		printf("Verify range extends beyond allocated memory\n");
		return;
	}

	/* cast the address to the pointer */
	mem_pointer = (uint32_t *) address;

	uint32_t itr = 0;

	/* start timing */
	struct timeval start, end;
	gettimeofday(&start,NULL);

	/* perform the verification */
	uint32_t gen_num = check_prng(*seed);
	while (itr < num_words)
	{
		if (mem_pointer[itr] != gen_num)
		{
			printf("Error at %#lx: %#x should be %#x\n", (long unsigned int) &(mem_pointer[itr]), mem_pointer[itr], gen_num);
			return;
		}
		gen_num = check_prng(gen_num);
		itr++;
	}

	gettimeofday(&end,NULL);
	unsigned long int micros_elapsed = 1000000 * end.tv_sec + end.tv_usec - (1000000 * start.tv_sec + start.tv_usec);

	printf("Verified memory from %#lx to %#lx in %lu us\n", address, address + 4*(itr-1), micros_elapsed);

}