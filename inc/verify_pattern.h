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

void verify_pattern(uint32_t ** start_mem, uint32_t ** end_mem, const bool * alloc_status, const char address_arg[16], const char num_words_arg[16], uint32_t * seed);

#endif /* __VERIFY_PATTERN_H_ */