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
#ifndef ___TEST_LINEAR_SEARCH_H
#define ___TEST_LINEAR_SEARCH_H

#include "shortcut.h"
#include "config.h"

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

#endif
