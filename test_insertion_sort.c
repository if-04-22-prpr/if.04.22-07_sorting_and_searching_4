/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for insertion sort
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for insertion sort.
 * ----------------------------------------------------------
 */

#include "test_insertion_sort.h"

#include "insertion_sort.h"
#include "test_sorting_algorithms.h"


#ifdef LIST_VARIANT

TEST(test_insertion_sort_ascending) {
    ASSERT_SORTED_LIST_ASCENDING_PLAIN(&insertion_sort_list);
}

TEST(test_insertion_sort_descending) {
    ASSERT_SORTED_LIST_DESCENDING_PLAIN(&insertion_sort_list);
}

TEST(test_insertion_sort_ascending_multiple) {
    ASSERT_SORTED_LIST_ASCENDING_MULTIPLE(&insertion_sort_list);
}

TEST(test_insertion_sort_descending_multiple) {
    ASSERT_SORTED_LIST_DESCENDING_MULTIPLE(&insertion_sort_list);
}

TEST(test_insertion_sort_ascending_reverse) {
    ASSERT_SORTED_LIST_ASCENDING_REVERSE(&insertion_sort_list);
}

TEST(test_insertion_sort_descending_reverse) {
    ASSERT_SORTED_LIST_DESCENDING_REVERSE(&insertion_sort_list);
}


#else /* ARRAY VARIANT */


TEST(test_insertion_sort_ascending) {
    ASSERT_SORTED_ARRAY_ASCENDING_PLAIN(&insertion_sort_array);
}

TEST(test_insertion_sort_descending) {
    ASSERT_SORTED_ARRAY_DESCENDING_PLAIN(&insertion_sort_array);
}

TEST(test_insertion_sort_ascending_multiple) {
    ASSERT_SORTED_ARRAY_ASCENDING_MULTIPLE(&insertion_sort_array);
}

TEST(test_insertion_sort_descending_multiple) {
    ASSERT_SORTED_ARRAY_DESCENDING_MULTIPLE(&insertion_sort_array);
}

TEST(test_insertion_sort_ascending_reverse) {
    ASSERT_SORTED_ARRAY_ASCENDING_REVERSE(&insertion_sort_array);
}

TEST(test_insertion_sort_descending_reverse) {
    ASSERT_SORTED_ARRAY_DESCENDING_REVERSE(&insertion_sort_array);
}

#endif