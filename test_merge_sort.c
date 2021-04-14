/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for merge sort
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for merge sort.
 * ----------------------------------------------------------
 */

#include "test_merge_sort.h"

#include "merge_sort.h"
#include "test_sorting_algorithms.h"


#ifdef LIST_VARIANT

TEST(test_merge_sort_ascending) {
    ASSERT_SORTED_LIST_ASCENDING_PLAIN(&merge_sort_list);
}

TEST(test_merge_sort_descending) {
    ASSERT_SORTED_LIST_DESCENDING_PLAIN(&merge_sort_list);
}

TEST(test_merge_sort_ascending_multiple) {
    ASSERT_SORTED_LIST_ASCENDING_MULTIPLE(&merge_sort_list);
}

TEST(test_merge_sort_descending_multiple) {
    ASSERT_SORTED_LIST_DESCENDING_MULTIPLE(&merge_sort_list);
}

TEST(test_merge_sort_ascending_reverse) {
    ASSERT_SORTED_LIST_ASCENDING_REVERSE(&merge_sort_list);
}

TEST(test_merge_sort_descending_reverse) {
    ASSERT_SORTED_LIST_DESCENDING_REVERSE(&merge_sort_list);
}


#else /* ARRAY VARIANT */


TEST(test_merge_sort_ascending) {
    ASSERT_SORTED_ARRAY_ASCENDING_PLAIN(&merge_sort_array);
}

TEST(test_merge_sort_descending) {
    ASSERT_SORTED_ARRAY_DESCENDING_PLAIN(&merge_sort_array);
}

TEST(test_merge_sort_ascending_multiple) {
    ASSERT_SORTED_ARRAY_ASCENDING_MULTIPLE(&merge_sort_array);
}

TEST(test_merge_sort_descending_multiple) {
    ASSERT_SORTED_ARRAY_DESCENDING_MULTIPLE(&merge_sort_array);
}

TEST(test_merge_sort_ascending_reverse) {
    ASSERT_SORTED_ARRAY_ASCENDING_REVERSE(&merge_sort_array);
}

TEST(test_merge_sort_descending_reverse) {
    ASSERT_SORTED_ARRAY_DESCENDING_REVERSE(&merge_sort_array);
}

#endif