/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Unit Tests for linear search functions
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for linear search.
 * ----------------------------------------------------------
 */

#include "test_linear_search.h"

#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "config.h"

#include "linear_search.h"

#ifdef LIST_VARIANT

#define ASSERT_FIND_IN_LIST(list_size, search_val_idx, multiple) _assert_find_in_list(tc, list_size, search_val_idx, multiple)
static void _assert_find_in_list(struct TestCase* tc, int list_size, int search_val_idx, bool multiple) {
    IntList list = list_obtain();
    ASSERT_TRUE(list_is_valid(list), MSG("Expected valid list"));
    for (int i = 1; i <= list_size; i++) {
        list_insert(list, i * 10);
        if (multiple) {
            list_insert(list, i * 10);
        }
    }

    search_val_idx *= (multiple ? 2 : 1);
    int search_val = list_get_at(list, (search_val_idx < 0 ? search_val_idx * -1 : search_val_idx));
    if (search_val_idx < 0) {
        search_val--;
    }
    int res_idx = linear_search_list(list, search_val);

    if (search_val_idx < 0) {
        ASSERT_TRUE(res_idx < 0, MSG("Expected item %d not found but got index %d", search_val, res_idx));
    } else {
        ASSERT_TRUE(res_idx == search_val_idx, MSG("Expected item %d @ index %d but was %d", search_val, search_val_idx, res_idx));
    }
    list_release(&list);
}

#else /* ARRAY VARIANT */

#define ASSERT_FIND_IN_ARRAY(array_size, search_val_idx, multiple) _assert_find_in_array(tc, array_size, search_val_idx, multiple)
static void _assert_find_in_array(struct TestCase* tc, int array_size, int search_val_idx, bool multiple) {
    int size = array_size * (multiple ? 2 : 1);
    int array[size];
    for (int i = 0; i < size; i++) {
        array[i] = (i + 1) * 10;
        if (multiple) {
            i++;
            array[i] = i * 10;
        }
    }

    search_val_idx *= (multiple ? 2 : 1);
    int search_val = array[(search_val_idx < 0 ? search_val_idx * -1 : search_val_idx)];
    if (search_val_idx < 0) {
        search_val--;
    }
    int res_idx = linear_search_array(array, size, search_val);

    if (search_val_idx < 0) {
        ASSERT_TRUE(res_idx < 0, MSG("Expected item %d not found but got index %d", search_val, res_idx));
    } else {
        ASSERT_TRUE(res_idx == search_val_idx, MSG("Expected item %d @ index %d but was %d", search_val, search_val_idx, res_idx));
    }
}
#endif

#ifdef LIST_VARIANT

TEST(test_linear_search_list__shall_find_first_item);
TEST(test_linear_search_list__shall_find_middle_item);
TEST(test_linear_search_list__shall_find_last_item);
TEST(test_linear_search_list__shall_find_first_item_in_ambiguous_values);
TEST(test_linear_search_list__shall_find_middle_item_in_ambiguous_values);
TEST(test_linear_search_list__shall_find_last_item_in_ambiguous_values);
TEST(test_linear_search_list__shall_not_find_missing_value);

#else 

TEST(test_linear_search_array__shall_find_first_item);
TEST(test_linear_search_array__shall_find_middle_item);
TEST(test_linear_search_array__shall_find_last_item);
TEST(test_linear_search_array__shall_find_first_item_in_ambiguous_values);
TEST(test_linear_search_array__shall_find_middle_item_in_ambiguous_values);
TEST(test_linear_search_array__shall_find_last_item_in_ambiguous_values);
TEST(test_linear_search_array__shall_not_find_missing_value);

#endif

#ifdef LIST_VARIANT


TEST(test_linear_search_list__shall_find_first_item) {
    ASSERT_FIND_IN_LIST(16, 0, false);
}

TEST(test_linear_search_list__shall_find_middle_item) {
    ASSERT_FIND_IN_LIST(16, 8, false);
}

TEST(test_linear_search_list__shall_find_last_item) {
    ASSERT_FIND_IN_LIST(16, 15, false);
}

TEST(test_linear_search_list__shall_find_first_item_in_ambiguous_values) {
    ASSERT_FIND_IN_LIST(16, 0, true);
}

TEST(test_linear_search_list__shall_find_middle_item_in_ambiguous_values) {
    ASSERT_FIND_IN_LIST(16, 8, true);
}

TEST(test_linear_search_list__shall_find_last_item_in_ambiguous_values) {
    ASSERT_FIND_IN_LIST(16, 15, true);
}

TEST(test_linear_search_list__shall_not_find_missing_value){
    ASSERT_FIND_IN_LIST(16, -1, false);
}

#else 

TEST(test_linear_search_array__shall_find_first_item) {
    ASSERT_FIND_IN_ARRAY(16, 0, false);
}

TEST(test_linear_search_array__shall_find_middle_item) {
    ASSERT_FIND_IN_ARRAY(16, 8, false);
}

TEST(test_linear_search_array__shall_find_last_item) {
    ASSERT_FIND_IN_ARRAY(16, 15, false);
}

TEST(test_linear_search_array__shall_find_first_item_in_ambiguous_values) {
    ASSERT_FIND_IN_ARRAY(16, 0, true);
}

TEST(test_linear_search_array__shall_find_middle_item_in_ambiguous_values) {
    ASSERT_FIND_IN_ARRAY(16, 8, true);
}

TEST(test_linear_search_array__shall_find_last_item_in_ambiguous_values) {
    ASSERT_FIND_IN_ARRAY(16, 15, true);
}

TEST(test_linear_search_array__shall_not_find_missing_value){
    ASSERT_FIND_IN_ARRAY(16, -1, false);
}

#endif