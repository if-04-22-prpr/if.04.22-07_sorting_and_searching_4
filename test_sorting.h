/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Unit Tests for support functions
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for support functions.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_SORTING_H
#define ___TEST_SORTING_H

#include "shortcut.h"
#include "config.h"

TEST(test_sorting_get_algorithm_name__shall_provide_name);
#ifdef LIST_VARIANT
TEST(test_sorting_init_list_random__shall_initialize_the_list);
TEST(test_sorting_sort_list__shall_sort_the_list_ascending);
TEST(test_sorting_sort_list__shall_sort_the_list_descending);
#else 
TEST(test_sorting_init_array_random__shall_initialize_the_array);
TEST(test_sorting_sort_array__shall_sort_the_array_ascending);
TEST(test_sorting_sort_array__shall_sort_the_array_descending);
#endif

#endif
