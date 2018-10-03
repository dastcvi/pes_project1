/* File:     invert_mem.h
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Defines the invert memory function for ECEN 5813: Project 1
 */

#ifndef __INVERT_MEM_H_
#define __INVERT_MEM_H_

#include <stdbool.h>
#include <stdint.h>

void invert_mem(uint32_t ** start_mem, uint32_t ** end_mem, const bool * alloc_status, const char address_arg[16], const char value_arg[16]);

#endif /* __INVERT_MEM_H_ */