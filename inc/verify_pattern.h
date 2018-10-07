/* File:     verify_pattern.h
 * Author:   Alex St. Clair
 * Created:  9-24-2018
 *
 * Defines the verify pattern function for ECEN 5813: Project 1
 */

#ifndef __VERIFY_PATTERN_H_
#define __VERIFY_PATTERN_H_

#include <stdint.h>
#include <stdbool.h>

#define M_PRNG	(2^31)
#define A_PRNG	1103515245
#define C_PRNG	12345

uint32_t check_prng(uint32_t current);

void verify_pattern(char args[4][16], uint32_t ** mem_start, uint32_t ** mem_end, uint32_t * seed, bool * alloc_status);

#endif /* __VERIFY_PATTERN_H_ */