/* File:     free_mem.h
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Defines the free memory function for ECEN 5813: Project 1
 */

#ifndef __FREE_MEM_H_
#define __FREE_MEM_H_

#include <stdbool.h>
#include <stdint.h>

void free_mem(char args[4][16], uint32_t ** mem_start, uint32_t ** mem_end, uint32_t * seed, bool * alloc_status);

#endif /* __FREE_MEM_H_ */