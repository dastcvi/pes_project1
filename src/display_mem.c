/* File:     display_mem.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Implements the display memory function for ECEN 5813: Project 1
 */

#include <stdio.h>
#include "../inc/display_mem.h"

void display_mem(char args[4][16], uint32_t ** mem_start, uint32_t ** mem_end, uint32_t * seed, bool * alloc_status)
{
	long unsigned int address = 0;
	uint32_t * mem_pointer = NULL;
	int num_words = 0;

	/* avoid unused parameter warnings caused by needing standard function prototype */
	(void)(mem_end);
	(void)(seed);
	(void)(alloc_status);

	/* read the first argument (start address) */
	if (1 != sscanf(args[1], "%lx", &address))
	{
		printf("Invalid display address: %s\n", args[1]);
		return;
	}

	/* check if it's the magic address */
	if (address == 0xffffffff) {
		address = (unsigned long int) *mem_start;
	}
	
	/* use the address as the pointer */
	mem_pointer = (uint32_t *) address;

	/* read the second argument (number of words to display) */
	if (1 != sscanf(args[2], "%d", &num_words))
	{
		printf("Invalid number of words: %s\n", args[2]);
		return;
	}

	/* verify that the number of words is within bounds */
	if (1 > num_words || num_words > MAX_DISPLAY_WORDS)
	{
		printf("Number of words to display must be between 1 and %d\n", MAX_DISPLAY_WORDS);
		return;
	}

	/* display the requested memory */
	int word_count = 0;
	for (word_count = 0; word_count < num_words; word_count++)
	{
		printf("%#x\n", mem_pointer[word_count]);
	}
}