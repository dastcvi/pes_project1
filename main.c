/* File:     main.c
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Main file for ECEN 5813: Project 1
 */

// reqs for sprint 1
// * welcome message
// * prompt
//    * help -> print helpful message (min contents: help)
//    * exit (not required)

#include <stdio.h>
#include <string.h>
#include "alloc_mem.h"
#include "display_mem.h"
#include "free_mem.h"
#include "help_mem.h"
#include "invert_mem.h"
#include "verify_pattern.h"
#include "write_mem.h"
#include "write_pattern.h"

void print_welcome(void)
{
	printf("\n----------------------------------------------------\n");
	printf("Welcome to MemManip, the memory manipulation program\n");
	printf("Author:  Alex St. Clair\n");
	printf("Created: 9-24-2018\n\n");
	printf("Enter \"help\" to see a command directory\n");
	printf("----------------------------------------------------\n\n");
}

int handle_selection(void)
{
	// statically allocate a buffer for user input
	static char user_input[16] = {0};

	printf("\nEnter a command: ");
	scanf("%15s", user_input);
	fflush(stdout);

	if (0 == strcmp(user_input, "help"))
	{
		help_mem();
	}
	else if (0 == strcmp(user_input, "exit"))
	{
		printf("Thank you\n\n");
		return 0;
	}
	else
	{
		printf("Unknown command \"%s\": try \"help\" for a command directory\n", user_input);
	}

	return 1;
}

int main()
{
	print_welcome();
	
	while (handle_selection());

	return 1;
}