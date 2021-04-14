/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for quick sort
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for quick sort.
 * ----------------------------------------------------------
 */

#include "test_quick_sort.h"

#include "quick_sort.h"
#include "test_sorting_algorithms.h"


#ifdef LIST_VARIANT

TEST(test_quick_sort_ascending) {
    ASSERT_SORTED_LIST_ASCENDING_PLAIN(&quick_sort_list);
}

TEST(test_quick_sort_descending) {
    ASSERT_SORTED_LIST_DESCENDING_PLAIN(&quick_sort_list);
}

TEST(test_quick_sort_ascending_multiple) {
    ASSERT_SORTED_LIST_ASCENDING_MULTIPLE(&quick_sort_list);
}

TEST(test_quick_sort_descending_multiple) {
    ASSERT_SORTED_LIST_DESCENDING_MULTIPLE(&quick_sort_list);
}

TEST(test_quick_sort_ascending_reverse) {
    ASSERT_SORTED_LIST_ASCENDING_REVERSE(&quick_sort_list);
}

TEST(test_quick_sort_descending_reverse) {
    ASSERT_SORTED_LIST_DESCENDING_REVERSE(&quick_sort_list);
}


#else /* ARRAY VARIANT */


TEST(test_quick_sort_ascending) {
    ASSERT_SORTED_ARRAY_ASCENDING_PLAIN(&quick_sort_array);
}

TEST(test_quick_sort_descending) {
    ASSERT_SORTED_ARRAY_DESCENDING_PLAIN(&quick_sort_array);
}

TEST(test_quick_sort_ascending_multiple) {
    ASSERT_SORTED_ARRAY_ASCENDING_MULTIPLE(&quick_sort_array);
}

TEST(test_quick_sort_descending_multiple) {
    ASSERT_SORTED_ARRAY_DESCENDING_MULTIPLE(&quick_sort_array);
}

TEST(test_quick_sort_ascending_reverse) {
    ASSERT_SORTED_ARRAY_ASCENDING_REVERSE(&quick_sort_array);
}

TEST(test_quick_sort_descending_reverse) {
    ASSERT_SORTED_ARRAY_DESCENDING_REVERSE(&quick_sort_array);
}

#endif