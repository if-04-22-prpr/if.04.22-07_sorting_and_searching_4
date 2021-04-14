/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S07
 * Title:			Binary search implementation
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Implements the binary search algorithm
 * ----------------------------------------------------------
 */
#ifndef ___BINARY_SEARCH_H
#define ___BINARY_SEARCH_H

#include "list.h"
#include "sorting_criteria.h"

/* NOTE: Either list or array variant is required! */

/**
 * Searches the given needle within the given haystack using binary search approach.
 * 
 * Implementation hint: delegate the invocation to function `binary_search_list_limited(…)`.
 * 
 * @param haystack The sorted list in which the `needle` is searched.
 * @param criterion The pointer to the function that implements the sorting criterion of the list.
 * That function accepts two integer parameters and returns a boolean value.
 * @param needle The value to find within the haystack.
 * @return The index of the `needle` within the list if it was found or the position where the needle need to
 * be inserted into the sorted list if it is not included in the list. The insertion position is 
 * expressed as index with negative sign, so that the value can be inserted at index (-1 * result).
 */
int binary_search_list(<params>);

/**
 * Searches the given needle within the given haystack up the given length using binary search approach.
 * 
 * @param haystack The sorted list in which the `needle` is searched.
 * @param length The number of items to consider starting from the beginning of the haystack.
 * If the haystack contains more items, the remaining items are omitted from the search. If it contains
 * less items, the number of items are clipped to the size of the haystack.
 * @param criterion The pointer to the function that implements the sorting criterion of the list.
 * That function accepts two integer parameters and returns a boolean value.
 * @param needle The value to find within the haystack.
 * @return The index of the `needle` within the list if it was found or the position where the needle need to
 * be inserted into the sorted list if it is not included in the list. The insertion position is 
 * expressed as index with negative sign, so that the value can be inserted at index (-1 * result).
 */
<type> binary_search_list_limited(<params>);

/* ARRAY VARIANT */

/**
 * Searches the given needle within the given haystack using binary search approach.
 *  
 * @param haystack The sorted list in which the `needle` is searched.
 * @param length The length of the haystack array.
 * @param criterion The pointer to the function that implements the sorting criterion of the list.
 * That function accepts two integer parameters and returns a boolean value.
 * @param needle The value to find within the haystack.
 * @return The index of the `needle` within the list if it was found or the position where the needle need to
 * be inserted into the sorted list if it is not included in the list. The insertion position is 
 * expressed as index with negative sign, so that the value can be inserted at index (-1 * result).
 */
<type> binary_search_array(<params>);

#endif
