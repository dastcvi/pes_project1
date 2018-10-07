/* File:     write_mem.h
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Defines the write memory function for ECEN 5813: Project 1
 */

#ifndef __WRITE_MEM_H_
#define __WRITE_MEM_H_

#include <stdint.h>
#include <stdbool.h>

void write_mem(char args[4][16], uint32_t ** mem_start, uint32_t ** mem_end, uint32_t * seed, bool * alloc_status);

#endif /* __WRITE_MEM_H_ */