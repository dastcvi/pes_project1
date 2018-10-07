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

void alloc_mem(char args[4][16], uint32_t ** mem_start, uint32_t ** mem_end, uint32_t * seed, bool * alloc_status);

#endif /* __ALLOC_MEM_H_ */