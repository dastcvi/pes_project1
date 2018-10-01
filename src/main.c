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

uint32_t * mem_pointer = NULL;
bool alloc_status = false;

void print_welcome(void)
{
	printf("\n----------------------------------------------------\n");
	printf("Welcome to MemManip, the memory manipulation program\n");
	printf("Author:  Alex St. Clair\n");
	printf("Created: 9-24-2018\n\n");
	printf("Enter \"help\" to see a command directory\n");
	printf("----------------------------------------------------\n\n");
}

void get_args(char args[3][16])
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

			/* ensure there aren't more than three arguments */
			if (++arg_num == 3) break;
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

int handle_selection(void)
{
	char args[3][16] = {0};

	printf("\nEnter a command: ");

	get_args(args);

	/* handle command */
	if (0 == strcmp(args[0], "help"))
	{
		help_mem();
	}
	else if (0 == strcmp(args[0], "alloc"))
	{
		alloc_mem(&mem_pointer, &alloc_status, args[1]);
	}
	else if (0 == strcmp(args[0], "free"))
	{
		free_mem(&mem_pointer, &alloc_status);
	}
	else if (0 == strcmp(args[0], "display"))
	{
		display_mem();
	}
	else if (0 == strcmp(args[0], "write"))
	{
		write_mem();
	}
	else if (0 == strcmp(args[0], "invert"))
	{
		invert_mem();
	}
	else if (0 == strcmp(args[0], "pattern"))
	{
		write_pattern();
	}
	else if (0 == strcmp(args[0], "verify"))
	{
		verify_pattern();
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
	printf("Void *: %lu\n", sizeof(void *));
	printf("Int: %lu\n", sizeof(int));
	printf("UInt: %lu\n", sizeof(unsigned int));
	printf("LInt: %lu\n", sizeof(long int));
	printf("LUInt: %lu\n", sizeof(long unsigned int));

	print_welcome();
	
	while (handle_selection());

	return 1;
}