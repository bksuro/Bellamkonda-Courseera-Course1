/******************************************************************************
 * Copyright (C) 2019 by Subbarao Bellamkonda 
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Subbarao Bellamkonda is not liable for any misuse of the material.
 *
 *****************************************************************************/

/**
 * @file stats.c
 * @brief Main file for dev_c1m1 assignment
 *
 * @author Subbarao Bellamkonda
 * @date May 16 2019
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char *sortedArray;
  
  /* Statistics and Printing Functions Go Here */
  printf("Raw Data \n\n");
  print_array(test, SIZE);
  sortedArray = sort_array(test, SIZE);
  printf("\n\nSorted data \n\n");
  print_array(sortedArray, SIZE);
  printf("\n\nStatistics:::\n\n");
  print_statistics(test, SIZE);

}

void print_statistics(unsigned char array[], int arraySize) {
	double mean; 
	double median;
	unsigned char max;
	unsigned char min;
	
	mean = find_mean(array, arraySize);
	median = find_median(array, arraySize);
	max = find_maximum(array, arraySize);
	min = find_minimum(array, arraySize);
	
	printf("Maximum of the numbers: %d\n", max);
	printf("Minimum of the numbers: %d\n", max);
	printf("Mean of the numbers: %.2f\n", mean);
	printf("Median of the numbers: %.2f\n", median);
}

void print_array(unsigned char array[], int arraySize) {
	for(int idx=0; idx < arraySize; idx++) {
		printf("%d ",array[idx]);
		if (((idx+1)%8) == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

double find_median(unsigned char array[], int arraySize) {
	return 1;
}

double find_mean(unsigned char array[], int arraySize) {
	return 1;
}

unsigned char find_minimum(unsigned char array[], int arraySize) {
	return 1;
}

unsigned char find_maximum(unsigned char array[], int arraySize) {
	return 1;
}

unsigned char *sort_array(unsigned char array[], int arraySize) {
	return array;
}

