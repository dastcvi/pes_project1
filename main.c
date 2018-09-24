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
#include "alloc_mem.h"
#include "display_mem.h"
#include "free_mem.h"
#include "help_mem.h"
#include "invert_mem.h"
#include "verify_pattern.h"
#include "write_mem.h"
#include "write_pattern.h"

int main()
{
	printf("Welcome\n");
	alloc_mem();
	display_mem();
	free_mem();
	help_mem();
	invert_mem();
	verify_pattern();
	write_mem();
	write_pattern();
	return 1;
}