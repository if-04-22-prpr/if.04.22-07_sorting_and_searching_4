/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S07
 * Title:			Sorting criteria
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Interface for sorting algorithms
 * ----------------------------------------------------------
 */


#ifndef ___SORTING_CRITERIA_H
#define ___SORTING_CRITERIA_H

#include <stdbool.h>

/** 
 * Declaration of function pointer for comparison function. 
 * A criterion function determines whether or not the given 
 * values are in the order that is defined by the criterion.
 * 
 * @param int The value that is supposed being ordered before `snd`.
 * @param int The value that is supposed being ordered after `fst`.
 * @return True if `fst` IS actually ordered before `snd` 
 * (the values are in order), false otherwise.
 */
/* Note: Name the pointer type 'criterion_fn' */

/**
 * Determines whether or not `fst` is smaller than or equal to `snd` (ascending order).
 * 
 * @param fst The value that is supposed being smaller than `snd`.
 * @param snd The value to compare.
 * @return True if the criterion is satisfied, false otherwise.
 */
<type> is_in_asc_order(<params>);

/**
 * Determines whether or not `fst` is larger than or equal to `snd` (descending order).
 * 
 * @param fst The value that is supposed being smaller than `snd`.
 * @param snd The value to compare.
 * @return True if the criterion is satisfied, false otherwise.
 */
<type> is_in_desc_order(i<params>);

#endif