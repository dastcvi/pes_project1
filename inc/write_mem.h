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

void write_mem(uint32_t ** start_mem, uint32_t ** end_mem, const bool * alloc_status, const char address_arg[16], const char value_arg[16]);

#endif /* __WRITE_MEM_H_ */