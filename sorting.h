/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S07
 * Title:			Sorting support functions
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Interface for sorting algorithms
 * ----------------------------------------------------------
 */
#ifndef ___SORTING_H
#define ___SORTING_H

#include "config.h"
#include "sorting_criteria.h"
#include "list.h"

/* NOTE: Either list variant OR array variant of functions is required! */

/**
 * Enumeration of supported sorting algorithms.
 */

typedef enum {
    BUBBLE_SORT,
    FIRST_ALGORITHM = BUBBLE_SORT,
    INSERTION_SORT,
    MERGE_SORT,
    ALGORITHM_ENUM_END
} SortingAlgorithm;

/**
 * Provides the name of the given sorting algorithm.
 * 
 * @param algorithm The sorting algorithm
 * @return The name of the algorithm.
 */
<type> get_algorithm_name(<params>);


#ifdef LIST_VARIANT

/**
 * Initializes the given list with random elements.
 * 
 * @param list The list to initialize.
 * @param item_count The number of items to insert.
 */
void init_list_random(<params>);

/**
 * Prints the values stored in the given list.
 * 
 * @param prefix The optional text to print before values are printed.
 * @param list The list to dump.
 */
void print_list(char* prefix, IntList list);

/**
 * Sorts the given list using the given sorting algorithm.
 * 
 * @param array The array to sort.
 * @param algorithm The sorting algorithm to use.
 * @param criterion The pointer to the function that implements the sorting criterion.
 * That function accepts two integer parameters and returns a boolean value.
 */
void sort_list(<params>);

#else /* ARRAY_VARIANT */

/**
 * Initializes the given array with random elements.
 * 
 * @param array The array to initialize.
 * @param length The length of the array.
 */
void init_array_random(<params>);

/**
 * Prints the values stored in the given array.
 * 
 * @param array The array to dump.
 * @param length The number of array elements.
 */
void print_array(char* prefix, int array[], unsigned long length);

/**
 * Sorts the given array of the given length using the given sorting algorithm.
 * 
 * @param array The array to sort.
 * @param length The number of array elements.
 * @param algorithm The sorting algorithm to use.
 * @param criterion The pointer to the function that implements the sorting criterion.
 * That function accepts two integer parameters and returns a boolean value.
 */
void sort_array(<params>);

#endif /* ARRAY_VARIANT */

#endif
