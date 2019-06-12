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
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stdlib.h>
/**
 * @brief converts data from standard integer type to ASCII string 
 *
 * Given a set of integer data convert into ASCII string and provide  
 * a pointer to that data location
 *
 * @param data integer data to be converted to ASCII
 * @param ptr pointer to the location where converted string resides
 * @param base indicating the base to convert the string to
 *
 * @return ASCII string length.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief converts data from ASCII string to standard integer type   
 *
 * Given a set of ASCII string convert into integer data  and provide  
 * a pointer to that data location
 *
 * @param ptr pointer to the string that is to be converted
 * @param digits the number of digitis in the character set
 * @param base indicating the base to convert to
 *
 * @return 32-bit signed integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
