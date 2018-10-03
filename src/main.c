/* File:     main.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Main file for ECEN 5813: Project 1
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/alloc_mem.h"
#include "../inc/display_mem.h"
#include "../inc/free_mem.h"
#include "../inc/help_mem.h"
#include "../inc/invert_mem.h"
#include "../inc/verify_pattern.h"
#include "../inc/write_mem.h"
#include "../inc/write_pattern.h"

/* pointer to the first valid uint32_t address */
uint32_t * mem_start = NULL;

/* pointer to the last valid uint32_t address */
uint32_t * mem_end = NULL;

/* shows whether memory is currently allocated or not */
bool alloc_status = false;

/* stores the current seed in memory */
uint32_t seed = 0;

/* show a welcome message */
void print_welcome(void)
{
	printf("\n----------------------------------------------------\n");
	printf("Welcome to MemManip, the memory manipulation program\n");
	printf("Author:  Alex St. Clair\n");
	printf("Created: 9-24-2018\n\n");
	printf("Enter \"help\" to see a command directory\n");
	printf("----------------------------------------------------\n\n");
}

/* read up to three arguments from the command line into the argument buffer */
void get_args(char args[4][16])
{
	char new_char = 0;
	uint8_t arg_num = 0;
	uint8_t char_num = 0;

	/* read up to three arguments from the command line */
	while ('\n' != (new_char = getchar()))
	{
		/* arguments are space delimited */
		if (new_char == ' ')
		{
			char_num = 0;

			/* don't handle arguments past four */
			if (++arg_num == 4) break;
		}
		else
		{
			/* ensure we don't overrun the buffer */
			if (char_num == 14) break;

			/* add char to the appropriate argument */
			args[arg_num][char_num++] = new_char;
		}
	}
	
	/* clear stdin */
	while (new_char != '\n')
	{
		new_char = getchar();
	}
}

/* wait for and handle user input */
int handle_selection(void)
{
	char args[4][16] = {0};

	printf("\nEnter a command: ");

	get_args(args);

	/* handle command */
	if (0 == strcmp(args[0], "help"))
	{
		help_mem();
	}
	else if (0 == strcmp(args[0], "alloc"))
	{
		alloc_mem(&mem_start, &mem_end, &alloc_status, args[1]);
	}
	else if (0 == strcmp(args[0], "free"))
	{
		free_mem(&mem_start, &alloc_status);
	}
	else if (0 == strcmp(args[0], "display"))
	{
		display_mem(&mem_start, args[1], args[2]);
	}
	else if (0 == strcmp(args[0], "write"))
	{
		write_mem(&mem_start, &mem_end, &alloc_status, args[1], args[2]);
	}
	else if (0 == strcmp(args[0], "invert"))
	{
		invert_mem(&mem_start, &mem_end, &alloc_status, args[1], args[2]);
	}
	else if (0 == strcmp(args[0], "pattern"))
	{
		write_pattern(&mem_start, &mem_end, &alloc_status, args[1], args[2], args[3], &seed);
	}
	else if (0 == strcmp(args[0], "verify"))
	{
		verify_pattern(&mem_start, &mem_end, &alloc_status, args[1], args[2], &seed);
	}
	else if (0 == strcmp(args[0], "exit"))
	{
		printf("\nThank you\n\n");
		return 0;
	}
	else
	{
		printf("Unknown command \"%s\": try \"help\" for a command directory\n", args[0]);
	}

	return 1;
}

int main()
{
	print_welcome();
	
	while (handle_selection());

	return 1;
}