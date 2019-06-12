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
 * Following functions are implemented in this file:
 *     main
 *     print_statistics
 *     print_array
 *     sort_array
 *     find_mean
 *     find_median
 *     find_maximum
 *     find_minimum
 *
 */


#include <stdio.h>
#include "stats.h"
#include "platform.h"

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

/***** This function prints statistics *****/
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
	printf("Minimum of the numbers: %d\n", min);
	printf("Mean of the numbers: %.2f\n", mean);
	printf("Median of the numbers: %.2f\n", median);
}

/***** This function prints the numbers in the array *****/
void print_array(unsigned char array[], int arraySize) {
#ifdef VERBOSE
	for(int idx=0; idx < arraySize; idx++) {
		PRINTF("%d ",array[idx]);
		if (((idx+1)%8) == 0) {
			PRINTF("\n");
		}
	}
	PRINTF("\n");
#endif
}

/***** This function finds the median from the array *****/
double find_median(unsigned char array[], int arraySize) {
	unsigned char *sortedArray;
	double retMedian;
	unsigned char medianIdx;
	
	sortedArray = sort_array(array, arraySize);
	
	if (arraySize%2 == 0) {
		medianIdx = arraySize/2;
		retMedian = (sortedArray[medianIdx - 1] + sortedArray[medianIdx])/2.0;
	} else {
		medianIdx = (arraySize+1)/2;
		retMedian = sortedArray[medianIdx];
	}
	return retMedian;
}

/***** This function finds the mean from the array *****/
double find_mean(unsigned char array[], int arraySize) {
	double retMean;
	double totalSum;
	
	totalSum = 0;
	for ( int idx = 0; idx < arraySize; idx++) {
		totalSum += array[idx];
	}
	
	retMean = totalSum/arraySize;
	return retMean;
}

/***** This function finds the minimum number from the array *****/
unsigned char find_minimum(unsigned char array[], int arraySize) {
	unsigned char retMin;
	
	retMin = array[0];
	for (int idx = 0; idx < arraySize; idx++) {
		if (retMin > array[idx]) {
			retMin = array[idx];
		}
	}
	return retMin;
}

/***** This function finds the maximum number from the array *****/
unsigned char find_maximum(unsigned char array[], int arraySize) {
	unsigned char retMax;
	
	retMax = array[0];
	for (int idx = 0; idx < arraySize; idx++) {
		if (retMax < array[idx]) {
			retMax = array[idx];
		}
	}
	return retMax;
}

/***** This function sorts the array in descending order *****/
unsigned char *sort_array(unsigned char array[], int arraySize) {
	unsigned char *retSortArray;
	int temp;
	
	retSortArray = array;
	
	for (int idxI = 0; idxI < arraySize; idxI++) {
		for (int idxJ = 0; idxJ < arraySize; idxJ++) {
			temp = 0;
			//sorting in descending order for ascending change the > to <
			if (retSortArray[idxI] > retSortArray[idxJ]) {  
				temp = retSortArray[idxI];
				retSortArray[idxI] = retSortArray[idxJ];
				retSortArray[idxJ] = temp;
			}
		}
	}
	return retSortArray;
}

