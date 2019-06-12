/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Abstraction of data manipulations
 *
 * This header file provides an abstraction of data manipulations 
 * via function calls. 
 *
 * @author Subbarao Bellamkonda
 * @date June 11 2019
 *
 */
#include "data.h"
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
	
	uint8_t length = 0;
	
	// bases 2 to 16
	if ( (base < 2) || (base > 16) ) {
		return length;
	}
	
	//null ptr
	if ( ptr == NULL ) {
		return length;
	}
	
	if ( (base == 10) && (data < 0) ) {
		data = -data;
		*ptr++ = '-';
	}
	
	while ( (data/base) || (data%base)) {
		ptr[length++] = data%base + 0x30;
		data/=base;
	}
	
	ptr[length] = 0;
	
	my_reverse(ptr, length);
	return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
	
	int32_t rtn = 0;
	uint8_t negative = 0;
	
	// bases 2 to 16
	if ( (base < 2) || (base > 16) ) {
		return rtn;
	}
		
	//null ptr
	if ( ptr == NULL ) {
		return rtn;
	}
	
	if (*ptr == '-' ) {
		negative = 1;
		ptr++;
	}
	
	for(int idx = 0; idx < digits; idx++) {
		rtn = rtn*base + (*(ptr + idx) - 0x30);
	}
	
	if (negative == 1) {
		return -rtn;
	}
	else {
		return rtn;
	}
}
