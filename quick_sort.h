/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S07
 * Title:			Quick sort
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Implements the quick sort algorithm
 * ----------------------------------------------------------
 */
#ifndef ___QUICK_SORT_H
#define ___QUICK_SORT_H

#include "list.h"
#include "sorting_criteria.h"

/* NOTE: Either list or array variant is required! */

/**
 * Sorts the given list according to the quick sort algorithm.
 * 
 * @param list The list to be sorted.
 * @param criterion The pointer to the function that implements the sorting criterion.
 * That function accepts two integer parameters and returns a boolean value.
 */
void quick_sort_list(<params>);

/**
 * Sorts the given array according to the quick sort algorithm.
 * 
 * @param array The array to be sorted.
 * @param length The length of the array.
 * @param criterion The pointer to the function that implements the sorting criterion.
 * That function accepts two integer parameters and returns a boolean value.
 */
void quick_sort_array(<params>);

#endif
