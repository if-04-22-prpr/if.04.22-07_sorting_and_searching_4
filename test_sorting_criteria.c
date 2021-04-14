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

#include "test_sorting_criteria.h"

#include <stdio.h>

#include "shortcut.h"
#include "config.h"

#include "sorting_criteria.h"

/* ------------------------------------------------------------------- */

TEST(test_is_in_asc_order__shall_be_true_for_ascending_params) {
    ASSERT_TRUE(is_in_asc_order(1, 2), MSG("Expected true for ascending values"));
}
TEST(test_is_in_asc_order__shall_be_true_for_equal_params) {
    ASSERT_TRUE(is_in_asc_order(3, 3), MSG("Expected true for equal values"));
}
TEST(test_is_in_asc_order__shall_be_false_for_descending_params) {
    ASSERT_FALSE(is_in_asc_order(5, 4), MSG("Expected false for descending values"));
}
TEST(test_is_in_desc_order__shall_be_false_for_ascending_params) {
    ASSERT_FALSE(is_in_desc_order(11, 12), MSG("Expected false for ascending values"));
}
TEST(test_is_in_desc_order__shall_be_true_for_equal_params) {
    ASSERT_TRUE(is_in_desc_order(13, 13), MSG("Expected true for ascending values"));
}
TEST(test_is_in_desc_order__shall_be_true_for_descending_params) {
    ASSERT_TRUE(is_in_desc_order(15, 14), MSG("Expected true for descending values"));
}