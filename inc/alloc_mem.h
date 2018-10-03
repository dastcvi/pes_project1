/* File:     alloc_mem.h
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Defines the memory allocate function for ECEN 5813: Project 1
 */

#ifndef __ALLOC_MEM_H_
#define __ALLOC_MEM_H_

#include <stdint.h>
#include <stdbool.h>

#define MAX_ALLOC_WORDS		1048576

void alloc_mem(uint32_t ** mem_start, uint32_t ** mem_end, bool * alloc_status, const char num_words[16]);

#endif /* __ALLOC_MEM_H_ */