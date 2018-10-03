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

void free_mem(uint32_t ** mem_pointer, bool * alloc_status);

#endif /* __FREE_MEM_H_ */