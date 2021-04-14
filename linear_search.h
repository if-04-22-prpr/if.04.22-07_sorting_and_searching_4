/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S07
 * Title:			Linear search implementation
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Implements the linear search algorithm
 * ----------------------------------------------------------
 */
#ifndef ___LINEAR_SEARCH_H
#define ___LINEAR_SEARCH_H

#include "list.h"

/* NOTE: Either list or array variant is required! */

/**
 * Searches the given needle within the given haystack using linear search approach.
 * 
 * @param haystack The list in which the `needle` is searched.
 * @param needle The value to find within the haystack.
 * @return The index of the `needle` within the list or a value less than zero 
 * if the needle was not not found.
 */
<type> linear_search_list(<params>);


/* ARRAY VARIANT */

/**
 * Searches the given needle within the given haystack using binary search approach.
 *  
 * @param haystack The sorted list in which the `needle` is searched.
 * @param length The length of the haystack array.
 * @param needle The value to find within the haystack.
 * @return The index of the `needle` within the array or a value less than zero 
 * if the needle was not not found.
 */
<type> linear_search_array(<params>);

#endif
