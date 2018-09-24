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
#include "help_mem.h"

int main()
{
	printf("Welcome\n");
	help_mem();
	return 1;
}