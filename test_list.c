/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for lists
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions of a list.
 * ----------------------------------------------------------
 */

#include "test_list.h"

#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "config.h"

#include "list.h"
#include "allocator.h"

#define ASSERT_NEW_VALID_LIST() _assert_new_valid_list(tc)
IntList _assert_new_valid_list(struct TestCase* tc) {
    int exp_alloc_cnt = mem_get_alloc_call_cnt() + 1;
    IntList list = list_obtain();
    ASSERT_TRUE(list != 0, MSG("Expected non-null list"));
    ASSERT_TRUE(list_is_valid(list), MSG("Expected a valid list"));
    ASSERT_TRUE(list_is_empty(list), MSG("Expected an empty list"));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == exp_alloc_cnt, MSG("Expected mem_alloc being called exactly once, but was called %d time(s)", mem_get_alloc_call_cnt() - exp_alloc_cnt - 1));
    ASSERT_TRUE(mem_is_allocated(list), MSG("Expected obtained list1 is allocated using mem_alloc"));
    return list;
}

#define ASSERT_RESET_AND_NEW_VALID_LIST() _assert_reset_and_new_valid_list(tc)
IntList _assert_reset_and_new_valid_list(struct TestCase* tc) {
    mem_reset_stat();
    return _assert_new_valid_list(tc);
}


#define ASSERT_FREE_VALID_LIST(p_list) _assert_free_valid_list(tc, p_list, 2)
#define ASSERT_FREE_VALID_LIST_EXT(p_list, free_calls) _assert_free_valid_list(tc, p_list, free_calls)
void _assert_free_valid_list(struct TestCase* tc, IntList* p_list, int exp_free_cnt) {
    ASSERT_TRUE(p_list != 0 && list_is_valid(*p_list), MSG("Expected a valid list"));
    int exp_alloc_cnt = mem_get_alloc_call_cnt();
    ASSERT_TRUE(mem_is_allocated(*p_list), MSG("Expected that list to release was allocated using mem_alloc"));
    list_release(p_list);
    ASSERT_TRUE(p_list != 0 && *p_list == 0, MSG("Expected that list was set to 0"));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == exp_alloc_cnt, MSG("Expected mem_alloc being NOT called, but was called %d time(s)", mem_get_alloc_call_cnt() - exp_alloc_cnt));
    ASSERT_TRUE(mem_get_free_call_cnt() <= exp_free_cnt, MSG("Expected mem_free being called less than %d time(s), but was called %d time(s)", exp_free_cnt, mem_get_free_call_cnt()));
    ASSERT_FALSE(mem_is_allocated(*p_list), MSG("Expected that released list is not allocated anymore after release"));
}

#define ASSERT_MEM_STATUS_EXT(exp_alloc_call_cnt, exp_free_call_cnt, exp_block_cnt) _assert_mem_status_ext(tc, exp_alloc_call_cnt, exp_free_call_cnt, exp_block_cnt)
void _assert_mem_status_ext(struct TestCase* tc, int exp_alloc_call_cnt, int exp_free_call_cnt, int exp_block_cnt) {
    ASSERT_TRUE(mem_get_allocated_block_cnt() == exp_block_cnt, MSG("Expected %d allocated memory block(s), but is %d", exp_block_cnt, mem_get_allocated_block_cnt()));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == exp_alloc_call_cnt, MSG("Expected %d mem_alloc() call(s), but is %d", exp_alloc_call_cnt, mem_get_alloc_call_cnt()));
    ASSERT_TRUE(mem_get_free_call_cnt() == exp_free_call_cnt, MSG("Expected %d mem_free() call(s), but is %d", exp_free_call_cnt, mem_get_free_call_cnt()));
}

#define ASSERT_MEM_STATUS(exp_alloc_call_cnt, exp_free_call_cnt) _assert_mem_status_ext(tc, exp_alloc_call_cnt, exp_free_call_cnt, (exp_alloc_call_cnt - exp_free_call_cnt))
/* ------------------------------------------------------------------- */

TEST(test_list_obtain__shall_allocate_a_list) {
    int exp_alloc_cnt = 1;
    mem_reset_stat();
    IntList list = list_obtain();
    ASSERT_TRUE(list != 0, MSG("Expected non-null list"));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == exp_alloc_cnt, MSG("Expected mem_alloc being called exactly %d time(s)", exp_alloc_cnt));
    ASSERT_TRUE(mem_is_allocated(list), MSG("Expected obtained list is allocated using mem_alloc"));
    if (list != 0) {
        free(list);
    }
}

TEST(test_list_obtain__shall_allocate_a_fresh_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    if (list != 0) {
        free(list);
    }
}

TEST(test_list_obtain__shall_allocate_a_different_list) {
    IntList list1 = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList list2 = ASSERT_NEW_VALID_LIST();
    ASSERT_TRUE(list1 != list2, MSG("Expected different lists"));
    if (list1 != 0) {
        free(list1);
    }
    if (list2 != 0) {
        free(list2);
    }
}

TEST(test_list_obtain_failed__shall_not_allocate_a_list) {
    IntList list1 = ASSERT_RESET_AND_NEW_VALID_LIST();
    int exp_alloc_cnt = 1;
    mem_reset_calls();
    mem_block_allocs(true);
    IntList list = list_obtain();
    ASSERT_TRUE(list == 0, MSG("Expected null list"));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == exp_alloc_cnt, MSG("Expected mem_alloc being called exactly %d time(s)", exp_alloc_cnt));
    if (list != 0) {
        free(list);
    }
    free(list1);
}



TEST(test_list_release__shall_release_a_valid_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_FREE_VALID_LIST(&list);
    ASSERT_TRUE(list == 0, MSG("Expected that list is set to 0"));
}

TEST(test_list_release__shall_release_a_valid_filled_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    list_insert(list, 12);
    ASSERT_FREE_VALID_LIST(&list);
    ASSERT_TRUE(list == 0, MSG("Expected that list is set to 0"));
}

TEST(test_list_release__shall_ignore_release_of_an_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    int block_cnt = mem_get_allocated_block_cnt();
    IntList* p_list = 0;
    list_release(p_list);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == block_cnt, MSG("Expected unchanged memory allocation"));
    ASSERT_TRUE(mem_get_free_call_cnt() == 0, MSG("Expected NO mem_free() call, but was called %d time(s)", mem_get_free_call_cnt()));

    IntList list = 0;
    p_list = &list;
    list_release(p_list);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == block_cnt, MSG("Expected unchanged memory allocation"));
    ASSERT_TRUE(mem_get_free_call_cnt() == 0, MSG("Expected NO mem_free() call, but was called %d time(s)", mem_get_free_call_cnt()));

    list_release(&tmp);
}



TEST(test_list_is_valid__shall_be_true_for_valid_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_is_valid(list), MSG("Expected list to be valid"));
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_is_valid__shall_be_false_for_invalid_list) {
    ASSERT_FALSE(list_is_valid(0), MSG("Expected list to be invalid"));
}



TEST(test_list_insert__shall_add_one_value_to_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_insert__shall_add_multiple_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    ASSERT_MEM_STATUS(2, 0);
    list_insert(list, 12);
    ASSERT_MEM_STATUS(2, 0);
    list_insert(list, 13);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_insert__shall_add_many_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    for (int i = 0; i < 3 * CAPACITY_INCREMENT; i++) {
        list_insert(list, 10*i+1);
    }
    bool inserted_all = true;
    for (int i = 0; i < 3 * CAPACITY_INCREMENT; i++) {
        inserted_all = inserted_all && (list_get_at(list, i) == 10*i+1);
    }
    ASSERT_TRUE(inserted_all, MSG("Values are missing or in wrong order when inserting more values than CAPACITY_INCREMENT"));
    ASSERT_MEM_STATUS(4, 2);
    ASSERT_FREE_VALID_LIST_EXT(&list, 4);
}

TEST(test_list_insert__shall_ignore_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(0, 11);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_remove__shall_not_remove_from_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_remove(list, 11);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove__shall_remove_only_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    list_remove(list, 11);
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove__shall_remove_one_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    list_insert(list, 12);
    list_insert(list, 11);
    list_insert(list, 11);
    list_remove(list, 11);
    ASSERT_TRUE(list_get_at(list, 0) == 12, MSG("Expected that the fist occurrance was removed"));
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove__shall_remove_first_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    list_insert(list, 12);
    list_insert(list, 13);
    list_remove(list, 11);
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove__shall_remove_value_in_the_middle) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    list_insert(list, 12);
    list_insert(list, 13);
    list_remove(list, 12);
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove__shall_remove_value_at_the_end) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    list_insert(list, 12);
    list_insert(list, 13);
    list_remove(list, 13);
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove__shall_not_remove_missing_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    list_insert(list, 12);
    list_insert(list, 13);
    list_remove(list, 14);
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove__shall_ignore_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_remove(0, 11);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_remove_all__shall_not_remove_from_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_remove_all(list, 21);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_all__shall_remove_only_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 21);
    list_remove_all(list, 21);
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_all__shall_remove_all_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 21);
    list_insert(list, 21);
    list_insert(list, 21);
    list_remove_all(list, 21);
    ASSERT_TRUE(list_is_empty(list), MSG("Expected list is empty after removal of all nodes"));
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_all__shall_remove_one_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 21);
    list_insert(list, 22);
    list_insert(list, 21);
    list_remove_all(list, 22);
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_all__shall_remove_all_values_in_a_row) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 21);
    list_insert(list, 22);
    list_insert(list, 22);
    list_insert(list, 22);
    list_insert(list, 23);
    list_remove_all(list, 22);
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_all__shall_remove_all_distributed_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 22);
    list_insert(list, 23);
    list_insert(list, 22);
    list_insert(list, 24);
    list_insert(list, 22);
    list_remove_all(list, 22);
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_all__shall_not_remove_missing_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 22);
    list_insert(list, 23);
    list_insert(list, 22);
    list_insert(list, 24);
    list_insert(list, 22);
    list_remove_all(list, 21);
    ASSERT_MEM_STATUS(2, 0); // list and node alloc, node free
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_all__shall_ignore_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_remove_all(0, 21);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_insert_at__shall_insert_single_value_in_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert_at(list, 0, 31);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_insert_at__shall_insert_value_at_the_beginning) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    list_insert(list, 12);
    list_insert(list, 13);
    list_insert_at(list, 0, 31);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_TRUE(list_get_at(list, 0) == 31, MSG("Expected value was inserted at the beginning of the list"));
    ASSERT_TRUE(list_get_at(list, 1) == 11, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 1, 11, list_get_at(list, 1)));
    ASSERT_TRUE(list_get_at(list, 2) == 12, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 2, 12, list_get_at(list, 2)));
    ASSERT_TRUE(list_get_at(list, 3) == 13, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 3, 13, list_get_at(list, 3)));
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_insert_at__shall_insert_value_in_the_middle) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    list_insert(list, 12);
    list_insert(list, 13);
    list_insert_at(list, 1, 31);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_TRUE(list_get_at(list, 0) == 11, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 0, 11, list_get_at(list, 0)));
    ASSERT_TRUE(list_get_at(list, 1) == 31, MSG("Expected value was inserted in the middle of the list"));
    ASSERT_TRUE(list_get_at(list, 2) == 12, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 2, 12, list_get_at(list, 2)));
    ASSERT_TRUE(list_get_at(list, 3) == 13, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 3, 13, list_get_at(list, 3)));
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_insert_at__shall_insert_value_at_the_end) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    list_insert(list, 12);
    list_insert(list, 13);
    list_insert_at(list, 3, 31);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_TRUE(list_get_at(list, 0) == 11, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 0, 11, list_get_at(list, 0)));
    ASSERT_TRUE(list_get_at(list, 1) == 12, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 1, 12, list_get_at(list, 1)));
    ASSERT_TRUE(list_get_at(list, 2) == 13, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 2, 13, list_get_at(list, 2)));
    ASSERT_TRUE(list_get_at(list, 3) == 31, MSG("Expected value was inserted before at the end of the list"));
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_insert_at__shall_insert_value_after_the_end) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 11);
    list_insert(list, 12);
    list_insert(list, 13);
    list_insert_at(list, 99, 31);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_TRUE(list_get_at(list, 0) == 11, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 0, 11, list_get_at(list, 0)));
    ASSERT_TRUE(list_get_at(list, 1) == 12, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 1, 12, list_get_at(list, 1)));
    ASSERT_TRUE(list_get_at(list, 2) == 13, MSG("Original order of list items is disturbed: #%d: exp.: %d, act. %d", 2, 13, list_get_at(list, 2)));
    ASSERT_TRUE(list_get_at(list, 3) == 31, MSG("Expected value was inserted before at the end of the list"));
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_insert_at__shall_ignore_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert_at(0, 2, 31);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_remove_at__shall_not_remove_from_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_remove_at(list, 0);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_at__shall_remove_value_at_the_beginning) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 41);
    list_insert(list, 42);
    list_insert(list, 43);
    int val = list_remove_at(list, 0);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_TRUE(list_get_at(list, 0) == 42, MSG("Expected value was removed form the beginning of the list"));
    ASSERT_TRUE(val == 41, MSG("Expected value %d was removed, but got %d", 41, val));
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_at__shall_remove_value_in_the_middle) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 41);
    list_insert(list, 42);
    list_insert(list, 43);
    int val = list_remove_at(list, 1);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_TRUE(list_get_at(list, 1) == 43, MSG("Expected value was removed form the middle of the list"));
    ASSERT_TRUE(val == 42, MSG("Expected value %d was removed, but got %d", 42, val));
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_at__shall_remove_value_at_the_end) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 41);
    list_insert(list, 42);
    list_insert(list, 43);
    int val = list_remove_at(list, 2);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_TRUE(list_get_at(list, 1) == 42, MSG("Expected value was removed form the end of the list"));
    ASSERT_TRUE(val == 43, MSG("Expected value %d was removed, but got %d", 43, val));
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_at__shall_not_remove_value_after_the_end) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 41);
    list_insert(list, 42);
    list_insert(list, 43);
    int val = list_remove_at(list, 3);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_TRUE(val == 0, MSG("Expected that no value (0) was removed, but got %d", val));
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_remove_at__shall_ignore_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    int val = list_remove_at(0, 0);
    ASSERT_TRUE(val == 0, MSG("Expected that no value (0) was removed, but got %d", val));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_clear__shall_clear_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_clear(list);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_clear__shall_clear_list_with_one_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 51);
    list_clear(list);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_clear__shall_clear_list_with_multiple_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 51);
    list_insert(list, 52);
    list_insert(list, 53);
    list_clear(list);
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_clear__shall_ingore_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_clear(0);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_is_empty__shall_be_true__for_newly_obtained_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_is_empty(0), MSG("Expected that new list IS empty"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_is_empty__shall_be_false__after_adding_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 61);
    ASSERT_FALSE(list_is_empty(list), MSG("Expected that list with values IS NOT empty"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_is_empty__shall_be_true__after_clear) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 51);
    list_insert(list, 52);
    list_insert(list, 53);
    list_clear(list);
    ASSERT_FALSE(list_is_empty(0), MSG("Expected that list IS empty after list_clear"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_is_empty__shall_be_true_for_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_is_empty(0), MSG("Expected that invalid list IS empty"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_get_size__shall_be_0_for_newly_obtained_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_get_size(list) == 0, MSG("Expected that size of new list is 0"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_size__shall_reflect_number_of_values_after_adding_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 71);
    ASSERT_TRUE(list_get_size(list) == 1, MSG("Expected that size of list is 1 after adding first value"));
    list_insert(list, 72);
    ASSERT_TRUE(list_get_size(list) == 2, MSG("Expected that size of list is 2 after adding second value"));
    list_insert(list, 73);
    ASSERT_TRUE(list_get_size(list) == 3, MSG("Expected that size of list is 3 after adding third value"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_size__shall_reflect_number_of_values_after_removing_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 81);
    list_insert(list, 82);
    list_insert(list, 83);
    list_remove_at(list, 0);
    ASSERT_TRUE(list_get_size(list) == 2, MSG("Expected that size of list is 2 after removing first value"));
    list_remove_at(list, 1);
    ASSERT_TRUE(list_get_size(list) == 1, MSG("Expected that size of list is 1 after removing second value"));
    list_remove_at(list, 0);
    ASSERT_TRUE(list_get_size(list) == 0, MSG("Expected that size of list is 0 after removing third value"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_size__shall_be_0_after_clear) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 81);
    list_insert(list, 82);
    list_insert(list, 83);
    list_clear(list);
    ASSERT_TRUE(list_get_size(list) == 0, MSG("Expected that size of list is 0 after clearing the list"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_size__shall_be_0_for_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_get_size(0) == 0, MSG("Expected that size of invalid list is 0"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_contains__shall_be_false_for_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_FALSE(list_contains(list, 91), MSG("Expected that empty list does not contain any value"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_contains__shall_be_true_for_one_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 91);
    ASSERT_TRUE(list_contains(list, 91), MSG("Expected that list does contain the value"));
    list_insert(list, 92);
    ASSERT_TRUE(list_contains(list, 91), MSG("Expected that list does contain the value"));
    ASSERT_TRUE(list_contains(list, 92), MSG("Expected that list does contain the value"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_contains__shall_be_true_for_multiple_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 91);
    ASSERT_TRUE(list_contains(list, 91), MSG("Expected that list does contain the value"));
    list_insert(list, 91);
    ASSERT_TRUE(list_contains(list, 91), MSG("Expected that list does contain the value"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_contains__shall_be_false_form_missing_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 91);
    ASSERT_FALSE(list_contains(list, 94), MSG("Expected that list does NOT contain the value"));
    list_insert(list, 92);
    ASSERT_FALSE(list_contains(list, 94), MSG("Expected that list does NOT contain the value"));
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_contains__shall_be_false_for_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_FALSE(list_contains(0, 0), MSG("Expected that invalid list does not contain any value"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_swap__shall_swap_same_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    int values[]    = {51, 52, 53, 54};
    int exp_vals[]  = {51, 52, 53, 54};
    int len = sizeof(values)/sizeof(values[0]);
    for (int i = 0; i < len; i++) {
        list_insert(list, values[i]);
    }
    ASSERT_MEM_STATUS(2, 0);
    list_swap(list, 2, 2);
    for (int i = 0; i < len; i++) {
        int act_val = list_get_at(list, i);
        ASSERT_TRUE(act_val == exp_vals[i], MSG("Order of list items is wrong: #%d: exp.: %d, act. %d", i, exp_vals[i], act_val));
    }
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_swap__shall_swap_two_neighbor_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    int values[]    = {51, 52, 53, 54};
    int exp_vals[]  = {51, 53, 52, 54};
    int len = sizeof(values)/sizeof(values[0]);
    for (int i = 0; i < len; i++) {
        list_insert(list, values[i]);
    }
    ASSERT_MEM_STATUS(2, 0);
    list_swap(list, 2, 1);
    for (int i = 0; i < len; i++) {
        int act_val = list_get_at(list, i);
        ASSERT_TRUE(act_val == exp_vals[i], MSG("Order of list items is wrong: #%d: exp.: %d, act. %d", i, exp_vals[i], act_val));
    }
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_swap__shall_swap_the_first_and_the_last_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    int values[]    = {51, 52, 53};
    int exp_vals[]  = {53, 52, 51};
    int len = sizeof(values)/sizeof(values[0]);
    for (int i = 0; i < len; i++) {
        list_insert(list, values[i]);
    }
    ASSERT_MEM_STATUS(2, 0);
    list_swap(list, 0, 2);
    for (int i = 0; i < len; i++) {
        int act_val = list_get_at(list, i);
        ASSERT_TRUE(act_val == exp_vals[i], MSG("Order of list items is wrong: #%d: exp.: %d, act. %d", i, exp_vals[i], act_val));
    }
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_swap__shall_ignore_swap_of_index_out_of_bounds_1) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    int values[]    = {51, 52, 53};
    int exp_vals[]  = {51, 52, 53};
    int len = sizeof(values)/sizeof(values[0]);
    for (int i = 0; i < len; i++) {
        list_insert(list, values[i]);
    }
    ASSERT_MEM_STATUS(2, 0);
    list_swap(list, 3, 2);
    for (int i = 0; i < len; i++) {
        int act_val = list_get_at(list, i);
        ASSERT_TRUE(act_val == exp_vals[i], MSG("Order of list items is wrong: #%d: exp.: %d, act. %d", i, exp_vals[i], act_val));
    }
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_swap__shall_ignore_swap_of_index_out_of_bounds_2) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    int values[]    = {51, 52, 53};
    int exp_vals[]  = {51, 52, 53};
    int len = sizeof(values)/sizeof(values[0]);
    for (int i = 0; i < len; i++) {
        list_insert(list, values[i]);
    }
    ASSERT_MEM_STATUS(2, 0);
    list_swap(list, 1, 3);
    for (int i = 0; i < len; i++) {
        int act_val = list_get_at(list, i);
        ASSERT_TRUE(act_val == exp_vals[i], MSG("Order of list items is wrong: #%d: exp.: %d, act. %d", i, exp_vals[i], act_val));
    }
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_swap__shall_ignore_swap_of_index_out_of_bounds_3) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    int values[]    = {51, 52, 53};
    int exp_vals[]  = {51, 52, 53};
    int len = sizeof(values)/sizeof(values[0]);
    for (int i = 0; i < len; i++) {
        list_insert(list, values[i]);
    }
    ASSERT_MEM_STATUS(2, 0);
    list_swap(list, 3, 4);
    for (int i = 0; i < len; i++) {
        int act_val = list_get_at(list, i);
        ASSERT_TRUE(act_val == exp_vals[i], MSG("Order of list items is wrong: #%d: exp.: %d, act. %d", i, exp_vals[i], act_val));
    }
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_swap__shall_ignore_invalid_lists) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_swap(0, 3, 5);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_get_at__shall_return_0_for_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_get_at(list, 0) == 0, MSG("Expected that empty list provides always 0"));
    ASSERT_TRUE(list_get_at(list, 1) == 0, MSG("Expected that empty list provides always 0"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_at__shall_return_single_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 101);
    ASSERT_TRUE(list_get_at(list, 0) == 101, MSG("Expected that list provides the value"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_at__shall_return_first_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 101);
    list_insert(list, 102);
    list_insert(list, 103);
    ASSERT_TRUE(list_get_at(list, 0) == 101, MSG("Expected that list provides the value"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_at__shall_return_values_in_added_order) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_insert(list, 101);
    list_insert(list, 102);
    list_insert(list, 103);
    ASSERT_TRUE(list_get_at(list, 0) == 101, MSG("Expected that list provides the first value"));
    ASSERT_TRUE(list_get_at(list, 1) == 102, MSG("Expected that list provides the second value"));
    ASSERT_TRUE(list_get_at(list, 2) == 103, MSG("Expected that list provides the third value"));
    list_insert_at(list, 1, 104);
    ASSERT_TRUE(list_get_at(list, 0) == 101, MSG("Expected that list provides the first value"));
    ASSERT_TRUE(list_get_at(list, 1) == 104, MSG("Expected that list provides the new second value"));
    ASSERT_TRUE(list_get_at(list, 2) == 102, MSG("Expected that list provides the new third value"));
    ASSERT_TRUE(list_get_at(list, 3) == 103, MSG("Expected that list provides the new forth value"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_at__shall_return_0_for_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_get_at(0, 0) == 0, MSG("Expected that invalid list provides always 0"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_append__shall_append_empty_list_to_empty_list) {
    IntList list1 = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList list2 = ASSERT_NEW_VALID_LIST();
    list_append(list1, list2);
    ASSERT_TRUE(list_is_empty(list1), MSG("Expected that empty list "));
    ASSERT_FREE_VALID_LIST_EXT(&list1, 4);
    ASSERT_FREE_VALID_LIST_EXT(&list2, 4);
}

TEST(test_list_append__shall_append_filled_list_to_empty_list) {
    IntList list1 = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList list2 = ASSERT_NEW_VALID_LIST();
    list_insert(list2, 111);
    list_insert(list2, 112);
    list_insert(list2, 113);
    list_append(list1, list2);
    ASSERT_TRUE(list_get_at(list1, 0) == 111, MSG("Expected that list provides the first value"));
    ASSERT_TRUE(list_get_at(list1, 1) == 112, MSG("Expected that list provides the second value"));
    ASSERT_TRUE(list_get_at(list1, 2) == 113, MSG("Expected that list provides the third value"));
    ASSERT_TRUE(list_get_size(list1) == 3, MSG("Expected that size of appended list as the size of the resulting list"));
    ASSERT_TRUE(list_get_size(list2) == 0, MSG("Expected that the appended list is empty"));
    ASSERT_FREE_VALID_LIST_EXT(&list1, 4);
    ASSERT_FREE_VALID_LIST_EXT(&list2, 4);
}

TEST(test_list_append__shall_append_empty_list_to_filled_list) {
    IntList list1 = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList list2 = ASSERT_NEW_VALID_LIST();
    list_insert(list1, 121);
    list_insert(list1, 122);
    list_insert(list1, 123);
    list_append(list1, list2);
    ASSERT_TRUE(list_get_at(list1, 0) == 121, MSG("Expected that list provides the first value"));
    ASSERT_TRUE(list_get_at(list1, 1) == 122, MSG("Expected that list provides the second value"));
    ASSERT_TRUE(list_get_at(list1, 2) == 123, MSG("Expected that list provides the third value"));
    ASSERT_TRUE(list_get_size(list1) == 3, MSG("Expected that size of original list as the size of the resulting list"));
    ASSERT_TRUE(list_get_size(list2) == 0, MSG("Expected that the appended list is empty"));
    ASSERT_FREE_VALID_LIST_EXT(&list1, 4);
    ASSERT_FREE_VALID_LIST_EXT(&list2, 4);
}

TEST(test_list_append__shall_append_filled_list_to_filled_list) {
    IntList list1 = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList list2 = ASSERT_NEW_VALID_LIST();
    list_insert(list1, 131);
    list_insert(list1, 132);
    list_insert(list1, 133);
    list_insert(list2, 141);
    list_insert(list2, 142);
    list_insert(list2, 143);
    list_append(list1, list2);
    ASSERT_TRUE(list_get_at(list1, 0) == 131, MSG("Expected that list provides the first value"));
    ASSERT_TRUE(list_get_at(list1, 1) == 132, MSG("Expected that list provides the second value"));
    ASSERT_TRUE(list_get_at(list1, 2) == 133, MSG("Expected that list provides the third value"));
    ASSERT_TRUE(list_get_at(list1, 3) == 141, MSG("Expected that list provides the first value of appended list"));
    ASSERT_TRUE(list_get_at(list1, 4) == 142, MSG("Expected that list provides the second value of appended list"));
    ASSERT_TRUE(list_get_at(list1, 5) == 143, MSG("Expected that list provides the third value of appended list"));
    ASSERT_TRUE(list_get_size(list1) == 6, MSG("Expected that size of list is the size of both lists"));
    ASSERT_TRUE(list_get_size(list2) == 0, MSG("Expected that the appended list is empty"));
    ASSERT_FREE_VALID_LIST_EXT(&list1, 4);
    ASSERT_FREE_VALID_LIST_EXT(&list2, 4);
}

TEST(test_list_append__shall_ignore_invalid_lists) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_append(0, tmp);
    ASSERT_MEM_STATUS(1, 0);
    list_append(tmp, 0);
    ASSERT_MEM_STATUS(1, 0);
    list_append(0, 0);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}

TEST(test_list_split__shall_split_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList left = ASSERT_NEW_VALID_LIST();
    IntList right = ASSERT_NEW_VALID_LIST();
    list_split(list, left, right, 0);
    ASSERT_TRUE(list_is_empty(list), MSG("Expected that empty list "));
    ASSERT_TRUE(list_is_empty(left), MSG("Expected that empty left sublist "));
    ASSERT_TRUE(list_is_empty(right), MSG("Expected that empty right sublist "));
    ASSERT_FREE_VALID_LIST_EXT(&list, 4);
    ASSERT_FREE_VALID_LIST_EXT(&left, 4);
    ASSERT_FREE_VALID_LIST_EXT(&right, 4);
}

TEST(test_list_split__shall_split_list_with_one_item_at_left) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList left = ASSERT_NEW_VALID_LIST();
    IntList right = ASSERT_NEW_VALID_LIST();
    list_insert(list, 141);
    list_split(list, left, right, 0);
    ASSERT_TRUE(list_is_empty(list), MSG("Expected that empty list "));
    ASSERT_TRUE(list_is_empty(left), MSG("Expected that empty left sublist "));
    ASSERT_TRUE(list_get_size(right) == 1, MSG("Expected that right sublist has one item"));
    ASSERT_TRUE(list_get_at(right,  0) == 141, MSG("Expected that right sublist got the item"));
    ASSERT_FREE_VALID_LIST_EXT(&list, 6);
    ASSERT_FREE_VALID_LIST_EXT(&left, 6);
    ASSERT_FREE_VALID_LIST_EXT(&right, 6);

}

TEST(test_list_split__shall_split_list_with_one_item_at_right) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList left = ASSERT_NEW_VALID_LIST();
    IntList right = ASSERT_NEW_VALID_LIST();
    list_insert(list, 151);
    list_split(list, left, right, 1);
    ASSERT_TRUE(list_is_empty(list), MSG("Expected that empty list "));
    ASSERT_TRUE(list_get_size(left) == 1, MSG("Expected that left sublist has one item"));
    ASSERT_TRUE(list_get_at(left,  0) == 151, MSG("Expected that left sublist got the item"));
    ASSERT_TRUE(list_is_empty(right), MSG("Expected that empty right sublist "));
    ASSERT_FREE_VALID_LIST_EXT(&list, 6);
    ASSERT_FREE_VALID_LIST_EXT(&left, 6);
    ASSERT_FREE_VALID_LIST_EXT(&right, 6);

}

TEST(test_list_split__shall_split_list_in_the_middle) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList left = ASSERT_NEW_VALID_LIST();
    IntList right = ASSERT_NEW_VALID_LIST();
    list_insert(list, 161);
    list_insert(list, 162);
    list_insert(list, 163);
    list_insert(list, 164);
    list_insert(list, 165);
    list_split(list, left, right, 2);
    ASSERT_TRUE(list_is_empty(list), MSG("Expected that empty list "));
    ASSERT_TRUE(list_get_size(left) == 2, MSG("Expected that left sublist has two items"));
    ASSERT_TRUE(list_get_at(left, 0) == 161, MSG("Expected that left sublist got the 1st item"));
    ASSERT_TRUE(list_get_at(left, 1) == 162, MSG("Expected that left sublist got the 2nd item"));
    ASSERT_TRUE(list_get_size(right) == 3, MSG("Expected that right sublist has three items"));
    ASSERT_TRUE(list_get_at(right, 0) == 163, MSG("Expected that right sublist got the 3rd item"));
    ASSERT_TRUE(list_get_at(right, 1) == 164, MSG("Expected that right sublist got the 4th item"));
    ASSERT_TRUE(list_get_at(right, 2) == 165, MSG("Expected that right sublist got the 5th item"));
    ASSERT_FREE_VALID_LIST_EXT(&list, 6);
    ASSERT_FREE_VALID_LIST_EXT(&left, 6);
    ASSERT_FREE_VALID_LIST_EXT(&right, 6);
}

TEST(test_list_split__shall_split_list_at_size) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList left = ASSERT_NEW_VALID_LIST();
    IntList right = ASSERT_NEW_VALID_LIST();
    list_insert(list, 171);
    list_insert(list, 172);
    list_insert(list, 173);
    list_insert(list, 174);
    list_insert(list, 175);
    list_split(list, left, right, 5);
    ASSERT_TRUE(list_is_empty(list), MSG("Expected that empty list "));
    ASSERT_TRUE(list_get_size(left) == 5, MSG("Expected that left sublist has all items"));
    ASSERT_TRUE(list_get_at(left, 0) == 171, MSG("Expected that left sublist got the 1st item"));
    ASSERT_TRUE(list_get_at(left, 1) == 172, MSG("Expected that left sublist got the 2nd item"));
    ASSERT_TRUE(list_get_at(left, 2) == 173, MSG("Expected that left sublist got the 3rd item"));
    ASSERT_TRUE(list_get_at(left, 3) == 174, MSG("Expected that left sublist got the 4th item"));
    ASSERT_TRUE(list_get_at(left, 4) == 175, MSG("Expected that left sublist got the 5th item"));
    ASSERT_TRUE(list_is_empty(right), MSG("Expected that empty right sublist "));
    ASSERT_FREE_VALID_LIST_EXT(&list, 6);
    ASSERT_FREE_VALID_LIST_EXT(&left, 6);
    ASSERT_FREE_VALID_LIST_EXT(&right, 6);
}

TEST(test_list_split__shall_ignore_invalid_lists) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList left = ASSERT_NEW_VALID_LIST();
    IntList right = ASSERT_NEW_VALID_LIST();
    list_split(0, left, right, 1);
    list_split(list, 0, right, 1);
    list_split(list, left, 0, 1);
    ASSERT_FREE_VALID_LIST_EXT(&list, 4);
    ASSERT_FREE_VALID_LIST_EXT(&left, 4);
    ASSERT_FREE_VALID_LIST_EXT(&right, 4);
}


TEST(test_list_transfer_head__shall_transfer_from_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList target = ASSERT_NEW_VALID_LIST();
    list_transfer_head(list, target);
    ASSERT_TRUE(list_is_empty(list), MSG("Expected that empty list "));
    ASSERT_TRUE(list_is_empty(target), MSG("Expected that empty left sublist "));
    ASSERT_FREE_VALID_LIST_EXT(&list, 4);
    ASSERT_FREE_VALID_LIST_EXT(&target, 4);
}

TEST(test_list_transfer_head__shall_transfer_the_only_item) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList target = ASSERT_NEW_VALID_LIST();
    list_insert(list, 181);
    list_transfer_head(list, target);
    ASSERT_TRUE(list_is_empty(list), MSG("Expected that empty list "));
    ASSERT_TRUE(list_get_size(target) == 1, MSG("Expected that target list has one item "));
    ASSERT_TRUE(list_get_at(target, 0) == 181, MSG("Expected that target list got the 1st item"));
    ASSERT_FREE_VALID_LIST_EXT(&list, 4);
    ASSERT_FREE_VALID_LIST_EXT(&target, 4);
}

TEST(test_list_transfer_head__shall_transfer_one_item) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList target = ASSERT_NEW_VALID_LIST();
    list_insert(list, 191);
    list_insert(list, 192);
    list_transfer_head(list, target);
    ASSERT_TRUE(list_get_size(list) == 1, MSG("Expected that list has one item "));
    ASSERT_TRUE(list_get_size(target) == 1, MSG("Expected that target list has one item "));
    ASSERT_TRUE(list_get_at(target, 0) == 191, MSG("Expected that target list got the 1st item"));
    ASSERT_TRUE(list_get_at(list, 0) == 192, MSG("Expected that list kept the other item"));
    ASSERT_FREE_VALID_LIST_EXT(&list, 4);
    ASSERT_FREE_VALID_LIST_EXT(&target, 4);
}

TEST(test_list_transfer_head__shall_transfer_multiple_items_one_by_one) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList target = ASSERT_NEW_VALID_LIST();
    list_insert(list, 201);
    list_insert(list, 202);
    list_insert(list, 203);
    list_insert(list, 204);
    list_insert(list, 205);
    list_transfer_head(list, target);
    list_transfer_head(list, target);
    list_transfer_head(list, target);
    ASSERT_TRUE(list_get_size(list) == 2, MSG("Expected that list has two items left "));
    ASSERT_TRUE(list_get_size(target) == 3, MSG("Expected that target list has three items "));
    ASSERT_TRUE(list_get_at(target, 0) == 201, MSG("Expected that target list got the 1st item"));
    ASSERT_TRUE(list_get_at(target, 1) == 202, MSG("Expected that target list got the 2nd item"));
    ASSERT_TRUE(list_get_at(target, 2) == 203, MSG("Expected that target list got the 3rd item"));
    ASSERT_TRUE(list_get_at(list, 0) == 204, MSG("Expected that list kept the 4th item"));
    ASSERT_TRUE(list_get_at(list, 1) == 205, MSG("Expected that list kept the 5th item"));
    ASSERT_FREE_VALID_LIST_EXT(&list, 4);
    ASSERT_FREE_VALID_LIST_EXT(&target, 4);
}

TEST(test_list_transfer_head__shall_ignore_invalid_lists) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList target = ASSERT_NEW_VALID_LIST();
    list_transfer_head(0, target);
    list_transfer_head(list, 0);
    ASSERT_FREE_VALID_LIST_EXT(&list, 4);
    ASSERT_FREE_VALID_LIST_EXT(&target, 4);
}