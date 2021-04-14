/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implements common Unit Test functionality for sorting algorithms.
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Provides common tests functions for sorting algorithms.
 * ----------------------------------------------------------
 */

#include "test_sorting_algorithms.h"

#include <stdio.h>
#include <string.h>
#include "sorting.h"


void _assert_sorted_list(struct TestCase* tc, const char* direction_txt, list_sorting_fn* sorter, criterion_fn* criterion, criterion_fn* reverse_criterion, bool multiple) {
#ifdef LIST_VARIANT
    IntList list = list_obtain();
    ASSERT_TRUE(list_is_valid(list), MSG("Expected valid list"));
    init_list_random(list, 16);
    if (multiple) {
        list_insert_at(list, 0, 42);
        list_insert_at(list, 0, 42);
        list_insert_at(list, 10, 42);
    }
    if (reverse_criterion != 0) {
        sorter(list, reverse_criterion);
        int i = 1;
        for (; i < list_get_size(list) && reverse_criterion(list_get_at(list, i-1), list_get_at(list, i)); i++);
        ASSERT_TRUE(i == list_get_size(list), MSG("Expected that all elements are in reverse %s order as required for preparation", direction_txt));
    }
    sorter(list, criterion);
    int i = 1;
    for (; i < list_get_size(list) && criterion(list_get_at(list, i-1), list_get_at(list, i)); i++);
    ASSERT_TRUE(i == list_get_size(list), MSG("Expected that all elements are in %s order", direction_txt));
    list_release(&list);
#endif
}

// #else /* ARRAY VARIANT */

void _assert_sorted_array(struct TestCase* tc, const char* direction_txt, array_sorting_fn* sorter, criterion_fn* criterion, criterion_fn* reverse_criterion, bool multiple) {
#ifndef LIST_VARIANT
    int cnt = 16;
    int array[cnt];
    init_array_random(array, cnt);
    if (multiple) {
        array[0] = 42;
        array[1] = 42;
        array[11] = 42;
    }
    if (reverse_criterion != 0) {
        sorter(array, cnt, reverse_criterion);
        int i = 1;
        for (; i < cnt && reverse_criterion(array[i-1], array[i]); i++);
        ASSERT_TRUE(i == cnt, MSG("Expected that all elements are in reverse %s order as required for preparation", direction_txt));
    }
    sorter(array, cnt, criterion);
    int i = 1;
    for (; i < cnt && criterion(array[i-1], array[i]); i++);
    ASSERT_TRUE(i == cnt, MSG("Expected that all elements are in %s order", direction_txt));
#endif
}



// #endif