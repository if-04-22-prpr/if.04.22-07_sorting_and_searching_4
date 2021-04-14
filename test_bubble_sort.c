/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for bubble sort
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for bubble sort.
 * ----------------------------------------------------------
 */

#include "test_bubble_sort.h"

#include "bubble_sort.h"
#include "test_sorting_algorithms.h"


#ifdef LIST_VARIANT

TEST(test_bubble_sort_ascending) {
    ASSERT_SORTED_LIST_ASCENDING_PLAIN(&bubble_sort_list);
}

TEST(test_bubble_sort_descending) {
    ASSERT_SORTED_LIST_DESCENDING_PLAIN(&bubble_sort_list);
}

TEST(test_bubble_sort_ascending_multiple) {
    ASSERT_SORTED_LIST_ASCENDING_MULTIPLE(&bubble_sort_list);
}

TEST(test_bubble_sort_descending_multiple) {
    ASSERT_SORTED_LIST_DESCENDING_MULTIPLE(&bubble_sort_list);
}

TEST(test_bubble_sort_ascending_reverse) {
    ASSERT_SORTED_LIST_ASCENDING_REVERSE(&bubble_sort_list);
}

TEST(test_bubble_sort_descending_reverse) {
    ASSERT_SORTED_LIST_DESCENDING_REVERSE(&bubble_sort_list);
}


#else /* ARRAY VARIANT */


TEST(test_bubble_sort_ascending) {
    ASSERT_SORTED_ARRAY_ASCENDING_PLAIN(&bubble_sort_array);
}

TEST(test_bubble_sort_descending) {
    ASSERT_SORTED_ARRAY_DESCENDING_PLAIN(&bubble_sort_array);
}

TEST(test_bubble_sort_ascending_multiple) {
    ASSERT_SORTED_ARRAY_ASCENDING_MULTIPLE(&bubble_sort_array);
}

TEST(test_bubble_sort_descending_multiple) {
    ASSERT_SORTED_ARRAY_DESCENDING_MULTIPLE(&bubble_sort_array);
}

TEST(test_bubble_sort_ascending_reverse) {
    ASSERT_SORTED_ARRAY_ASCENDING_REVERSE(&bubble_sort_array);
}

TEST(test_bubble_sort_descending_reverse) {
    ASSERT_SORTED_ARRAY_DESCENDING_REVERSE(&bubble_sort_array);
}

#endif