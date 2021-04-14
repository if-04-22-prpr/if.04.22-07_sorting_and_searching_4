/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S07
 * Title:			Insertion sort implementation
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Implements the merge sort algorithm
 * ----------------------------------------------------------
 */
#ifndef ___MERGE_SORT_H
#define ___MERGE_SORT_H

#include "list.h"
#include "sorting_criteria.h"

/* NOTE: Either list or array variant is required! */

/**
 * Sorts the given list according to the merge sort algorithm.
 * 
 * @param list The list to be sorted.
 * @param criterion The pointer to the function that implements the sorting criterion.
 * That function accepts two integer parameters and returns a boolean value.
 */
void merge_sort_list(<params>);

/**
 * Sorts the given array according to the merge sort algorithm.
 * 
 * @param array The array to be sorted.
 * @param length The length of the array.
 * @param criterion The pointer to the function that implements the sorting criterion.
 * That function accepts two integer parameters and returns a boolean value.
 */
void merge_sort_array(<params>);

#endif
