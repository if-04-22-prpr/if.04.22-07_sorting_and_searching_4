/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Common Unit Test functionality for sorting algorithms.
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Provides common tests functions for sorting algorithms.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_SORTING_ALGORITHMS_H
#define ___TEST_SORTING_ALGORITHMS_H

#include "shortcut.h"
#include "config.h"
#include "list.h"
#include "sorting_criteria.h"

typedef void list_sorting_fn(IntList, criterion_fn*);

#define ASSERT_SORTED_LIST_ASCENDING_PLAIN(sorter)    ASSERT_SORTED_LIST_ASCENDING(sorter, 0, false);
#define ASSERT_SORTED_LIST_ASCENDING_MULTIPLE(sorter) ASSERT_SORTED_LIST_ASCENDING(sorter, 0, true);
#define ASSERT_SORTED_LIST_ASCENDING_REVERSE(sorter)  ASSERT_SORTED_LIST_ASCENDING(sorter, &is_in_desc_order, false);
#define ASSERT_SORTED_LIST_ASCENDING(sorter, reverse_criterion, multiple) ASSERT_SORTED_LIST("ascending", sorter, &is_in_asc_order, reverse_criterion, multiple);

#define ASSERT_SORTED_LIST_DESCENDING_PLAIN(sorter)    ASSERT_SORTED_LIST_DESCENDING(sorter, 0, false);
#define ASSERT_SORTED_LIST_DESCENDING_MULTIPLE(sorter) ASSERT_SORTED_LIST_DESCENDING(sorter, 0, true);
#define ASSERT_SORTED_LIST_DESCENDING_REVERSE(sorter)  ASSERT_SORTED_LIST_DESCENDING(sorter, &is_in_asc_order, false);
#define ASSERT_SORTED_LIST_DESCENDING(sorter, reverse_criterion, multiple) ASSERT_SORTED_LIST("descending", sorter, &is_in_desc_order, reverse_criterion, multiple);

#define ASSERT_SORTED_LIST(direction_txt, sorter, criterion, reverse_criterion, multiple) _assert_sorted_list(tc, direction_txt, sorter, criterion, reverse_criterion, multiple)
void _assert_sorted_list(struct TestCase* tc, const char* direction_txt, list_sorting_fn* sorter, criterion_fn* criterion, criterion_fn* reverse_criterion, bool multiple);


typedef void array_sorting_fn(int[], unsigned long, criterion_fn*);

#define ASSERT_SORTED_ARRAY_ASCENDING_PLAIN(sorter)    ASSERT_SORTED_ARRAY_ASCENDING(sorter, 0, false);
#define ASSERT_SORTED_ARRAY_ASCENDING_MULTIPLE(sorter) ASSERT_SORTED_ARRAY_ASCENDING(sorter, 0, true);
#define ASSERT_SORTED_ARRAY_ASCENDING_REVERSE(sorter)  ASSERT_SORTED_ARRAY_ASCENDING(sorter, &is_in_desc_order, false);
#define ASSERT_SORTED_ARRAY_ASCENDING(sorter, reverse_criterion, multiple) ASSERT_SORTED_ARRAY("ascending", sorter, &is_in_asc_order, reverse_criterion, multiple);

#define ASSERT_SORTED_ARRAY_DESCENDING_PLAIN(sorter)    ASSERT_SORTED_ARRAY_DESCENDING(sorter, 0, false);
#define ASSERT_SORTED_ARRAY_DESCENDING_MULTIPLE(sorter) ASSERT_SORTED_ARRAY_DESCENDING(sorter, 0, true);
#define ASSERT_SORTED_ARRAY_DESCENDING_REVERSE(sorter)  ASSERT_SORTED_ARRAY_DESCENDING(sorter, &is_in_asc_order, false);
#define ASSERT_SORTED_ARRAY_DESCENDING(sorter, reverse_criterion, multiple) ASSERT_SORTED_ARRAY("descending", sorter, &is_in_desc_order, reverse_criterion, multiple);

#define ASSERT_SORTED_ARRAY(direction_txt, sorter, criterion, reverse_criterion, multiple) _assert_sorted_array(tc, direction_txt, sorter, criterion, reverse_criterion, multiple)
void _assert_sorted_array(struct TestCase* tc, const char* direction_txt, array_sorting_fn* sorter, criterion_fn* criterion, criterion_fn* reverse_criterion, bool multiple);

// #ifdef LIST_VARIANT
// TEST(test_insertion_sort_binsearch_list_ascending);
// TEST(test_insertion_sort_binsearch_list_decending);
// #else 
// TEST(test_insertion_sort_binsearch_array_ascending);
// TEST(test_insertion_sort_binsearch_array_descending);
// TEST(test_insertion_sort_binsearch_array_ascending_multiple);
// TEST(test_insertion_sort_binsearch_array_descending_multiple);
// TEST(test_insertion_sort_binsearch_array_ascending_reverse);
// TEST(test_insertion_sort_binsearch_array_descending_reverse); 
// #endif
#endif