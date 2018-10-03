/* File:     display_mem.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Implements the display memory function for ECEN 5813: Project 1
 */

#include <stdio.h>
#include "../inc/display_mem.h"

void display_mem(uint32_t ** start_mem, const char address_arg[16], const char num_words_arg[16])
{
	long unsigned int address = 0;
	uint32_t * mem_pointer = NULL;
	int num_words = 0;

	if (1 != sscanf(address_arg, "%lx", &address))
	{
		printf("Invalid display address: %s\n", address_arg);
		return;
	}

	if (address == 0xffffffff) {
		address = (unsigned long int) *start_mem;
	}
	
	mem_pointer = (uint32_t *) address;

	if (1 != sscanf(num_words_arg, "%d", &num_words))
	{
		printf("Invalid number of words: %s\n", num_words_arg);
		return;
	}

	if (1 > num_words || num_words > MAX_DISPLAY_WORDS)
	{
		printf("Number of words to display must be between 1 and %d\n", MAX_DISPLAY_WORDS);
		return;
	}

	int word_count = 0;
	for (word_count = 0; word_count < num_words; word_count++)
	{
		printf("%#x\n", mem_pointer[word_count]);
	}
}