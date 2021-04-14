/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Unit Tests for sorting criteria implementation
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for sorting criteria.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_SORTING_CRITERIA_H
#define ___TEST_SORTING_CRITERIA_H

#include "shortcut.h"

TEST(test_is_in_asc_order__shall_be_true_for_ascending_params);
TEST(test_is_in_asc_order__shall_be_true_for_equal_params);
TEST(test_is_in_asc_order__shall_be_false_for_descending_params);
TEST(test_is_in_desc_order__shall_be_false_for_ascending_params);
TEST(test_is_in_desc_order__shall_be_true_for_equal_params);
TEST(test_is_in_desc_order__shall_be_true_for_descending_params);

#endif
