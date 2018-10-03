/* File:     display_mem.h
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Defines the display memory function for ECEN 5813: Project 1
 */

#ifndef __DISPLAY_MEM_H_
#define __DISPLAY_MEM_H_

#include <stdint.h>

#define MAX_DISPLAY_WORDS	1048576

void display_mem(uint32_t ** start_mem, const char address_arg[16], const char num_words_arg[16]);

#endif /* __DISPLAY_MEM_H_ */