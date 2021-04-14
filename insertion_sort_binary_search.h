/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S07
 * Title:			Insertion sort implementation
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Implements the insertion sort algorithm using binary search
 * ----------------------------------------------------------
 */
#ifndef ___INSERTION_SORT_BINARY_SEARCH_H
#define ___INSERTION_SORT_BINARY_SEARCH_H

#include "list.h"
#include "sorting_criteria.h"

/* NOTE: Either list or array variant is required! */

/**
 * Sorts the given list according to the insertion sort algorithm using binary.
 * 
 * @param list The list to be sorted.
 * @param criterion The pointer to the function that implements the sorting criterion.
 * That function accepts two integer parameters and returns a boolean value.
 */
void insertion_sort_binsearch_list(<params>);

/**
 * Sorts the given array according to the insertion sort algorithm using binary search.
 * 
 * @param array The array to be sorted.
 * @param length The length of the array.
 * @param criterion The pointer to the function that implements the sorting criterion.
 * That function accepts two integer parameters and returns a boolean value.
 */
void insertion_sort_binsearch_array(<params>);

#endif
