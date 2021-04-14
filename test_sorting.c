/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for support functions
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for support functions.
 * ----------------------------------------------------------
 */

#include "test_sorting.h"

#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "config.h"

#include "sorting.h"


/* ------------------------------------------------------------------- */

TEST(test_sorting_get_algorithm_name__shall_provide_name) {
    char* name = get_algorithm_name(BUBBLE_SORT);
    ASSERT_TRUE(name != 0 && strlen(name) > 0, MSG("Expected name for bubble sort algorithm"));
    name = get_algorithm_name(INSERTION_SORT);
    ASSERT_TRUE(name != 0 && strlen(name) > 0, MSG("Expected name for insertion sort algorithm"));
}

#ifdef LIST_VARIANT

TEST(test_sorting_init_list_random__shall_initialize_the_list) {
    IntList list = list_obtain();
    if (list != 0) {
        init_list_random(list, 16);
        ASSERT_TRUE(list_get_size(list) == 16, MSG("Expected that the list was initialized with a number of values"));
        list_release(&list);
    }
}

TEST(test_sorting_sort_list__shall_sort_the_list_ascending) {
    IntList list = list_obtain();
    if (list != 0) {
        init_list_random(list, 16);
        sort_list(list, BUBBLE_SORT, &is_in_asc_order);
        int i = 1;
        for (; i < list_get_size(list) && list_get_at(list, i-1) <= list_get_at(list, i); i++);
        ASSERT_TRUE(i == list_get_size(list), MSG("Expected that all elements are in ascending order"));
        list_release(&list);
    }
}

TEST(test_sorting_sort_list__shall_sort_the_list_descending) {
    IntList list = list_obtain();
    if (list != 0) {
        init_list_random(list, 16);
        sort_list(list, INSERTION_SORT, &is_in_desc_order);
        int i = 1;
        for (; i < list_get_size(list) && list_get_at(list, i-1) >= list_get_at(list, i); i++);
        ASSERT_TRUE(i == list_get_size(list), MSG("Expected that all elements are in descending order"));
        list_release(&list);
    }
}

#else

TEST(test_sorting_init_array_random__shall_initialize_the_array) {
    int array[16];
    int cnt = 16;
    init_array_random(array, cnt);
    int i = 1;
    for (; i < cnt && array[i] != 0; i++);
    ASSERT_TRUE(i == 16, MSG("Expected that the array was initialized with a number of values"));
}

TEST(test_sorting_sort_array__shall_sort_the_array_ascending) {
    int array[16];
    int cnt = 16;
    init_array_random(array, cnt);
    sort_array(array, cnt, BUBBLE_SORT, &is_in_asc_order);
    int i = 1;
    for (; i < cnt && array[i-1] <= array[i]; i++);
    ASSERT_TRUE(i == cnt, MSG("Expected that all elements are in ascending order"));
}

TEST(test_sorting_sort_array__shall_sort_the_array_descending) {
    int array[16];
    int cnt = 16;
    init_array_random(array, cnt);
    sort_array(array, cnt, INSERTION_SORT, &is_in_desc_order);
    int i = 1;
    for (; i < cnt && array[i-1] >= array[i]; i++);
    ASSERT_TRUE(i == cnt, MSG("Expected that all elements are in descending order"));
}

#endif