/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Unit Tests for binary search functions
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Teests functions for binary search.
 * ----------------------------------------------------------
 */

#include "test_binary_search.h"

#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "config.h"

#include "binary_search.h"

#ifdef LIST_VARIANT

#define ASSERT_FIND_IN_LIST(list_size, search_limit, search_val_idx, multiple) _assert_find_in_list(tc, list_size, search_limit, search_val_idx, multiple)
static void _assert_find_in_list(struct TestCase* tc, int list_size, int search_limit, int search_val_idx, bool multiple) {
    IntList list = list_obtain();
    ASSERT_TRUE(list_is_valid(list), MSG("Expected valid list"));
    for (int i = 1; i <= list_size; i++) {
        list_insert(list, i * 10);
        if (multiple) {
            list_insert(list, i * 10);
        }
    }

    search_limit *= (multiple ? 2 : 1);
    search_val_idx *= (multiple ? 2 : 1);
    int search_val = list_get_at(list, (search_val_idx < 0 ? search_val_idx * -1 : search_val_idx));
    if (search_val_idx < 0) {
        search_val--;
    }
    int res_idx = (search_limit < list_get_size(list)) 
            ? binary_search_list(list, &is_in_asc_order, search_val) 
            : binary_search_list_limited(list, search_limit, &is_in_asc_order, search_val);

    if (multiple) {
        if (search_val_idx < 0) {
            ASSERT_TRUE(res_idx == search_val_idx, MSG("Expected item %d @ index %d but was %d", search_val, search_val_idx, res_idx));
        } else {
            ASSERT_TRUE(res_idx == search_val_idx || res_idx == search_val_idx + 1, MSG("Expected item %d @ index %d or %d but was %d", search_val, search_val_idx, search_val_idx + 1, res_idx));
        }
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
    int res_idx = binary_search_array(array, size, &is_in_asc_order, search_val);

    if (multiple) {
        if (search_val_idx < 0) {
            ASSERT_TRUE(res_idx == search_val_idx, MSG("Expected item %d @ index %d but was %d", search_val, search_val_idx, res_idx));
        } else {
            ASSERT_TRUE(res_idx == search_val_idx || res_idx == search_val_idx + 1, MSG("Expected item %d @ index %d or %d but was %d", search_val, search_val_idx, search_val_idx + 1, res_idx));
        }
    } else {
        ASSERT_TRUE(res_idx == search_val_idx, MSG("Expected item %d @ index %d but was %d", search_val, search_val_idx, res_idx));
    }
}
#endif


#ifdef LIST_VARIANT


TEST(test_binary_search_list__shall_find_first_item) {
    ASSERT_FIND_IN_LIST(16, 16, 0, false);
}

TEST(test_binary_search_list__shall_find_middle_item) {
    ASSERT_FIND_IN_LIST(16, 16, 8, false);
}

TEST(test_binary_search_list__shall_find_last_item) {
    ASSERT_FIND_IN_LIST(16, 16, 15, false);
}

TEST(test_binary_search_list__shall_find_first_item_in_ambiguous_values) {
    ASSERT_FIND_IN_LIST(16, 16, 0, true);
}

TEST(test_binary_search_list__shall_find_middle_item_in_ambiguous_values) {
    ASSERT_FIND_IN_LIST(16, 16, 8, true);
}

TEST(test_binary_search_list__shall_find_last_item_in_ambiguous_values) {
    ASSERT_FIND_IN_LIST(16, 16, 15, true);
}

TEST(test_binary_search_list__shall_find_slot_at_beginning){
    ASSERT_FIND_IN_LIST(16, 16, -1, false);
}

TEST(test_binary_search_list__shall_find_slot_in_the_middle){
    ASSERT_FIND_IN_LIST(16, 16, -7, false);
}

TEST(test_binary_search_list__shall_find_slot_at_the_end){
    ASSERT_FIND_IN_LIST(16, 16, -15, false);
}
TEST(test_binary_search_list__shall_find_slot_at_beginning_in_ambiguous_values) {
    ASSERT_FIND_IN_LIST(16, 16, -1, true);
}

TEST(test_binary_search_list__shall_find_slot_in_the_middle_in_ambiguous_values){
    ASSERT_FIND_IN_LIST(16, 16, -8, true);
}

TEST(test_binary_search_list__shall_find_slot_at_the_end_in_ambiguous_values){
    ASSERT_FIND_IN_LIST(16, 16, -15, true);
}

TEST(test_binary_search_list_limited__shall_find_first_item) {
    ASSERT_FIND_IN_LIST(16, 10, 0, false);
}

TEST(test_binary_search_list_limited__shall_find_middle_item) {
    ASSERT_FIND_IN_LIST(16, 10, 5, false);
}

TEST(test_binary_search_list_limited__shall_find_last_item) {
    ASSERT_FIND_IN_LIST(16, 10, 9, false);
}

TEST(test_binary_search_list_limited__shall_find_first_item_in_ambiguous_values) {
    ASSERT_FIND_IN_LIST(16, 10, 0, true);
}

TEST(test_binary_search_list_limited__shall_find_middle_item_in_ambiguous_values) {
    ASSERT_FIND_IN_LIST(16, 10, 5, true);
}

TEST(test_binary_search_list_limited__shall_find_last_item_in_ambiguous_values) {
    ASSERT_FIND_IN_LIST(16, 10, 9, true);
}

TEST(test_binary_search_list_limited__shall_find_slot_at_beginning){
    ASSERT_FIND_IN_LIST(16, 10, -1, false);
}

TEST(test_binary_search_list_limited__shall_find_slot_in_the_middle){
    ASSERT_FIND_IN_LIST(16, 10, -5, false);
}

TEST(test_binary_search_list_limited__shall_find_slot_at_the_end){
    ASSERT_FIND_IN_LIST(16, 10, -9, false);
}

TEST(test_binary_search_list_limited__shall_find_slot_at_beginning_in_ambiguous_values) {
    ASSERT_FIND_IN_LIST(16, 10, -1, true);
}

TEST(test_binary_search_list_limited__shall_find_slot_in_the_middle_in_ambiguous_values){
    ASSERT_FIND_IN_LIST(16, 10, -5, true);
}

TEST(test_binary_search_list_limited__shall_find_slot_at_the_end_in_ambiguous_values){
    ASSERT_FIND_IN_LIST(16, 10, -9, true);
}

#else 

TEST(test_binary_search_array__shall_find_first_item) {
    ASSERT_FIND_IN_ARRAY(16, 0, false);
}

TEST(test_binary_search_array__shall_find_middle_item) {
    ASSERT_FIND_IN_ARRAY(16, 8, false);
}

TEST(test_binary_search_array__shall_find_last_item) {
    ASSERT_FIND_IN_ARRAY(16, 15, false);
}

TEST(test_binary_search_array__shall_find_first_item_in_ambiguous_values) {
    ASSERT_FIND_IN_ARRAY(16, 0, true);
}

TEST(test_binary_search_array__shall_find_middle_item_in_ambiguous_values) {
    ASSERT_FIND_IN_ARRAY(16, 8, true);
}

TEST(test_binary_search_array__shall_find_last_item_in_ambiguous_values) {
    ASSERT_FIND_IN_ARRAY(16, 15, true);
}

TEST(test_binary_search_array__shall_find_slot_at_beginning){
    ASSERT_FIND_IN_ARRAY(16, -1, false);
}

TEST(test_binary_search_array__shall_find_slot_in_the_middle){
    ASSERT_FIND_IN_ARRAY(16, -7, false);
}

TEST(test_binary_search_array__shall_find_slot_at_the_end){
    ASSERT_FIND_IN_ARRAY(16, -15, false);
}

TEST(test_binary_search_array__shall_find_slot_at_beginning_in_ambiguous_values) {
    ASSERT_FIND_IN_ARRAY(16, -1, true);
}

TEST(test_binary_search_array__shall_find_slot_in_the_middle_in_ambiguous_values){
    ASSERT_FIND_IN_ARRAY(16, -8, true);
}

TEST(test_binary_search_array__shall_find_slot_at_the_end_in_ambiguous_values){
    ASSERT_FIND_IN_ARRAY(16, -15, true);
}

#endif