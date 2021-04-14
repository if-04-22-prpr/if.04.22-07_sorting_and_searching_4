/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Unit Tests for binary search functions
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for binary search.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_BINARY_SEARCH_H
#define ___TEST_BINARY_SEARCH_H

#include "shortcut.h"
#include "config.h"

#ifdef LIST_VARIANT

TEST(test_binary_search_list__shall_find_first_item);
TEST(test_binary_search_list__shall_find_middle_item);
TEST(test_binary_search_list__shall_find_last_item);
TEST(test_binary_search_list__shall_find_first_item_in_ambiguous_values);
TEST(test_binary_search_list__shall_find_middle_item_in_ambiguous_values);
TEST(test_binary_search_list__shall_find_last_item_in_ambiguous_values);
TEST(test_binary_search_list__shall_find_slot_at_beginning);
TEST(test_binary_search_list__shall_find_slot_in_the_middle);
TEST(test_binary_search_list__shall_find_slot_at_the_end);
TEST(test_binary_search_list__shall_find_slot_at_beginning_in_ambiguous_values);
TEST(test_binary_search_list__shall_find_slot_in_the_middle_in_ambiguous_values);
TEST(test_binary_search_list__shall_find_slot_at_the_end_in_ambiguous_values);

TEST(test_binary_search_list_limited__shall_find_first_item);
TEST(test_binary_search_list_limited__shall_find_middle_item);
TEST(test_binary_search_list_limited__shall_find_last_item);
TEST(test_binary_search_list_limited__shall_find_first_item_in_ambiguous_values);
TEST(test_binary_search_list_limited__shall_find_middle_item_in_ambiguous_values);
TEST(test_binary_search_list_limited__shall_find_last_item_in_ambiguous_values);
TEST(test_binary_search_list_limited__shall_find_slot_at_beginning);
TEST(test_binary_search_list_limited__shall_find_slot_in_the_middle);
TEST(test_binary_search_list_limited__shall_find_slot_at_the_end);
TEST(test_binary_search_list_limited__shall_find_slot_at_beginning_in_ambiguous_values);
TEST(test_binary_search_list_limited__shall_find_slot_in_the_middle_in_ambiguous_values);
TEST(test_binary_search_list_limited__shall_find_slot_at_the_end_in_ambiguous_values);

#else 

TEST(test_binary_search_array__shall_find_first_item);
TEST(test_binary_search_array__shall_find_middle_item);
TEST(test_binary_search_array__shall_find_last_item);
TEST(test_binary_search_array__shall_find_first_item_in_ambiguous_values);
TEST(test_binary_search_array__shall_find_middle_item_in_ambiguous_values);
TEST(test_binary_search_array__shall_find_last_item_in_ambiguous_values);

TEST(test_binary_search_array__shall_find_slot_at_beginning);
TEST(test_binary_search_array__shall_find_slot_in_the_middle);
TEST(test_binary_search_array__shall_find_slot_at_the_end);
TEST(test_binary_search_array__shall_find_slot_at_beginning_in_ambiguous_values);
TEST(test_binary_search_array__shall_find_slot_in_the_middle_in_ambiguous_values);
TEST(test_binary_search_array__shall_find_slot_at_the_end_in_ambiguous_values);

#endif

#endif
