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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief moves a length of bytes from source to destination location
 *
 * Given a pointer to a byte location, this will moves a length of bytes
 * to a destination location.  
 *
 * @param src Pointer to a source location
 * @param dst Pointer to a destination location
 * @param size_t length of bytes to move
 *
 * @return pointer to the destination location.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief copies a length of bytes from source to destination location
 *
 * Given a pointer to a byte location, this will copy a length of bytes
 * to a destination location.  
 *
 * @param src Pointer to a source location
 * @param dst Pointer to a destination location
 * @param length length of bytes to copy
 *
 * @return pointer to the destination location.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief sets the memory at a memory location for the length of bytes
 *        with the value provided
 *
 * Given a pointer to a memory location, this will zero out a length of 
 * bytes.  
 *
 * @param src Pointer to a source location
 * @param length length of bytes to set
 * @param value value to set to
 *
 * @return pointer to the source location.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief zero out all of the memory at a memory location for the length
 *        of bytes
 *
 * Given a pointer to a memory location, this will zero out a length of 
 * bytes.  
 *
 * @param src Pointer to a source location
 * @param length length of bytes to zero out
 *
 * @return pointer to the source location.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief reverse the order of the length of bytes sent in
 *
 * Given a pointer to a byte location, this will reverse a length of bytes
 * at that location.  
 *
 * @param src Pointer to a source location
 * @param length length of bytes to reverse
 *
 * @return pointer to the source location.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief takes number of words to allocate in dynamic memory
 *
 * Given a length allocates words in memory
 *
 * @param length length of words to reserve
 *
 * @return pointer to the destination location.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief frees a dynamic memory allocation
 *
 * Given a pointer to a location, this will free memory at that location
 *
 * @param src Pointer to a source location
 *
 * @return void.
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
