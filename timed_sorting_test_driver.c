/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Title:			Tests implementation of a Liked List.
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Unit tests for a linked list implemenation.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

#include "config.h"

#include "shortcut.h"
#include "test_list.h"
#include "test_stopwatch.h"
#include "test_sorting_criteria.h"
#include "test_bubble_sort.h"
#include "test_insertion_sort.h"
#include "test_merge_sort.h"
#include "test_quick_sort.h"
#include "test_insertion_sort_binary_search.h"
#include "test_sorting.h"
#include "test_linear_search.h"
#include "test_binary_search.h"

int main(int argc, char *argv[])
{
	/* LIST */
	#ifdef LIST_VARIANT 
	ADD_TEST(test_list_obtain__shall_allocate_a_list);
	ADD_TEST(test_list_obtain__shall_allocate_a_fresh_list);
	ADD_TEST(test_list_obtain__shall_allocate_a_different_list);
	ADD_TEST(test_list_obtain_failed__shall_not_allocate_a_list);
	
	ADD_TEST(test_list_get_size__shall_be_0_for_newly_obtained_list);
	ADD_TEST(test_list_get_size__shall_reflect_number_of_values_after_adding_values);
	ADD_TEST(test_list_get_size__shall_reflect_number_of_values_after_removing_values);
	ADD_TEST(test_list_get_size__shall_be_0_after_clear);
	ADD_TEST(test_list_get_size__shall_be_0_for_invalid_list);

	ADD_TEST(test_list_release__shall_release_a_valid_empty_list);
	ADD_TEST(test_list_release__shall_release_a_valid_filled_list);
	ADD_TEST(test_list_release__shall_ignore_release_of_an_invalid_list);
	
	ADD_TEST(test_list_is_valid__shall_be_true_for_valid_list);
	ADD_TEST(test_list_is_valid__shall_be_false_for_invalid_list);
	
	ADD_TEST(test_list_is_empty__shall_be_true__for_newly_obtained_list);
	ADD_TEST(test_list_is_empty__shall_be_false__after_adding_values);
	ADD_TEST(test_list_is_empty__shall_be_true_for_invalid_list);
	
	ADD_TEST(test_list_insert__shall_add_one_value_to_empty_list);
	ADD_TEST(test_list_insert__shall_add_multiple_values);
	ADD_TEST(test_list_insert__shall_add_many_values);
	ADD_TEST(test_list_insert__shall_ignore_invalid_list);
	
	ADD_TEST(test_list_remove__shall_not_remove_from_empty_list);
	ADD_TEST(test_list_remove__shall_remove_only_value);
	ADD_TEST(test_list_remove__shall_remove_one_value);
	ADD_TEST(test_list_remove__shall_remove_first_value);
	ADD_TEST(test_list_remove__shall_remove_value_in_the_middle);
	ADD_TEST(test_list_remove__shall_remove_value_at_the_end);
	ADD_TEST(test_list_remove__shall_not_remove_missing_value);
	
	ADD_TEST(test_list_remove_all__shall_not_remove_from_empty_list);
	ADD_TEST(test_list_remove_all__shall_remove_only_value);
	ADD_TEST(test_list_remove_all__shall_remove_all_values);
	ADD_TEST(test_list_remove_all__shall_remove_one_value);
	ADD_TEST(test_list_remove_all__shall_remove_all_values_in_a_row);
	ADD_TEST(test_list_remove_all__shall_remove_all_distributed_values);
	ADD_TEST(test_list_remove_all__shall_not_remove_missing_value);
	ADD_TEST(test_list_remove_all__shall_ignore_invalid_list);
	
	ADD_TEST(test_list_insert_at__shall_insert_single_value_in_empty_list);
	ADD_TEST(test_list_insert_at__shall_insert_value_at_the_beginning);
	ADD_TEST(test_list_insert_at__shall_insert_value_in_the_middle);
	ADD_TEST(test_list_insert_at__shall_insert_value_at_the_end);
	ADD_TEST(test_list_insert_at__shall_insert_value_after_the_end);
	ADD_TEST(test_list_insert_at__shall_ignore_invalid_list);
	
	ADD_TEST(test_list_remove_at__shall_not_remove_from_empty_list);
	ADD_TEST(test_list_remove_at__shall_remove_value_at_the_beginning);
	ADD_TEST(test_list_remove_at__shall_remove_value_in_the_middle);
	ADD_TEST(test_list_remove_at__shall_not_remove_from_empty_list);
	ADD_TEST(test_list_remove_at__shall_remove_value_at_the_end);
	ADD_TEST(test_list_remove_at__shall_not_remove_value_after_the_end);
	ADD_TEST(test_list_remove_at__shall_ignore_invalid_list);
	
	ADD_TEST(test_list_clear__shall_clear_empty_list);
	ADD_TEST(test_list_clear__shall_clear_list_with_one_value);
	ADD_TEST(test_list_clear__shall_clear_list_with_multiple_values);
	ADD_TEST(test_list_clear__shall_ingore_invalid_list);
	
	ADD_TEST(test_list_contains__shall_be_false_for_empty_list);
	ADD_TEST(test_list_contains__shall_be_true_for_one_value);
	ADD_TEST(test_list_contains__shall_be_true_for_multiple_values);
	ADD_TEST(test_list_contains__shall_be_false_form_missing_value);
	ADD_TEST(test_list_contains__shall_be_false_for_invalid_list);
	
	ADD_TEST(test_list_swap__shall_swap_same_value);
	ADD_TEST(test_list_swap__shall_swap_two_neighbor_value);
	ADD_TEST(test_list_swap__shall_swap_the_first_and_the_last_value);
	ADD_TEST(test_list_swap__shall_ignore_swap_of_index_out_of_bounds_1);
	ADD_TEST(test_list_swap__shall_ignore_swap_of_index_out_of_bounds_2);
	ADD_TEST(test_list_swap__shall_ignore_swap_of_index_out_of_bounds_3);
	ADD_TEST(test_list_swap__shall_ignore_invalid_lists);

	ADD_TEST(test_list_get_at__shall_return_0_for_empty_list);
	ADD_TEST(test_list_get_at__shall_return_single_value);
	ADD_TEST(test_list_get_at__shall_return_first_value);
	ADD_TEST(test_list_get_at__shall_return_values_in_added_order);
	ADD_TEST(test_list_get_at__shall_return_0_for_invalid_list);

	ADD_TEST(test_list_append__shall_append_empty_list_to_empty_list);
	ADD_TEST(test_list_append__shall_append_filled_list_to_empty_list);
	ADD_TEST(test_list_append__shall_append_empty_list_to_filled_list);
	ADD_TEST(test_list_append__shall_append_filled_list_to_filled_list);
	ADD_TEST(test_list_append__shall_ignore_invalid_lists);
		
	ADD_TEST(test_list_split__shall_split_empty_list);
	ADD_TEST(test_list_split__shall_split_list_with_one_item_at_left);
	ADD_TEST(test_list_split__shall_split_list_with_one_item_at_right);
	ADD_TEST(test_list_split__shall_split_list_in_the_middle);
	ADD_TEST(test_list_split__shall_split_list_at_size);
	ADD_TEST(test_list_split__shall_ignore_invalid_lists);

	ADD_TEST(test_list_transfer_head__shall_transfer_from_empty_list);
	ADD_TEST(test_list_transfer_head__shall_transfer_the_only_item);
	ADD_TEST(test_list_transfer_head__shall_transfer_one_item);
	ADD_TEST(test_list_transfer_head__shall_transfer_multiple_items_one_by_one);
	ADD_TEST(test_list_transfer_head__shall_ignore_invalid_lists);

	#else /* ARRAY VARIANT */
	#endif /* ARRAY VARIANT */

	/* --- STOPWATCH --- */
	ADD_TEST(test_stopwatch_is_active__shall_provide_running_state);
	ADD_TEST(test_stopwatch_start__shall_provide_elapsed_time);
	ADD_TEST(test_stopwatch_start_stop__shall_provide_elapsed_time);
	ADD_TEST(test_stopwatch_start_stop_resume__shall_provide_elapsed_time);

	/* --- SORT CRITERIA --- */
	ADD_TEST(test_is_in_asc_order__shall_be_true_for_ascending_params);
	ADD_TEST(test_is_in_asc_order__shall_be_true_for_equal_params);
	ADD_TEST(test_is_in_asc_order__shall_be_false_for_descending_params);
	ADD_TEST(test_is_in_desc_order__shall_be_false_for_ascending_params);
	ADD_TEST(test_is_in_desc_order__shall_be_true_for_equal_params);
	ADD_TEST(test_is_in_desc_order__shall_be_true_for_descending_params);

	/* --- BUBBLE SORT --- */
	ADD_TEST(test_bubble_sort_ascending);
	ADD_TEST(test_bubble_sort_descending);
	ADD_TEST(test_bubble_sort_ascending_multiple);
	ADD_TEST(test_bubble_sort_descending_multiple);
	ADD_TEST(test_bubble_sort_ascending_reverse);
	ADD_TEST(test_bubble_sort_descending_reverse); 

	/* --- INSERTION SORT --- */
	ADD_TEST(test_insertion_sort_ascending);
	ADD_TEST(test_insertion_sort_descending);
	ADD_TEST(test_insertion_sort_ascending_multiple);
	ADD_TEST(test_insertion_sort_descending_multiple);
	ADD_TEST(test_insertion_sort_ascending_reverse);
	ADD_TEST(test_insertion_sort_descending_reverse); 

	/* --- MERGE SORT --- */
	ADD_TEST(test_merge_sort_ascending);
	ADD_TEST(test_merge_sort_descending);
	ADD_TEST(test_merge_sort_ascending_multiple);
	ADD_TEST(test_merge_sort_descending_multiple);
	ADD_TEST(test_merge_sort_ascending_reverse);
	ADD_TEST(test_merge_sort_descending_reverse); 

	/* --- QUICK SORT --- */
	ADD_TEST(test_quick_sort_ascending);
	ADD_TEST(test_quick_sort_descending);
	ADD_TEST(test_quick_sort_ascending_multiple);
	ADD_TEST(test_quick_sort_descending_multiple);
	ADD_TEST(test_quick_sort_ascending_reverse);
	ADD_TEST(test_quick_sort_descending_reverse); 

	/* --- INSERTION SORT WITH BINARY SEARCH --- */
	ADD_TEST(test_insertion_sort_binsearch_ascending);
	ADD_TEST(test_insertion_sort_binsearch_descending);
	ADD_TEST(test_insertion_sort_binsearch_ascending_multiple);
	ADD_TEST(test_insertion_sort_binsearch_descending_multiple);
	ADD_TEST(test_insertion_sort_binsearch_ascending_reverse);
	ADD_TEST(test_insertion_sort_binsearch_descending_reverse); 

	/* --- SORTING --- */
	ADD_TEST(test_sorting_get_algorithm_name__shall_provide_name);
	#ifdef LIST_VARIANT
	ADD_TEST(test_sorting_init_list_random__shall_initialize_the_list);
	ADD_TEST(test_sorting_sort_list__shall_sort_the_list_ascending);
	ADD_TEST(test_sorting_sort_list__shall_sort_the_list_descending);
	#else 
	ADD_TEST(test_sorting_init_array_random__shall_initialize_the_array);
	ADD_TEST(test_sorting_sort_array__shall_sort_the_array_ascending);
	ADD_TEST(test_sorting_sort_array__shall_sort_the_array_descending);
	#endif

	/* --- BINARY SEARCH --- */
	#ifdef LIST_VARIANT
	ADD_TEST(test_binary_search_list__shall_find_first_item);
	ADD_TEST(test_binary_search_list__shall_find_middle_item);
	ADD_TEST(test_binary_search_list__shall_find_last_item);
	ADD_TEST(test_binary_search_list__shall_find_first_item_in_ambiguous_values);
	ADD_TEST(test_binary_search_list__shall_find_middle_item_in_ambiguous_values);
	ADD_TEST(test_binary_search_list__shall_find_last_item_in_ambiguous_values);
	ADD_TEST(test_binary_search_list__shall_find_slot_at_beginning);
	ADD_TEST(test_binary_search_list__shall_find_slot_in_the_middle);
	ADD_TEST(test_binary_search_list__shall_find_slot_at_the_end);
	ADD_TEST(test_binary_search_list__shall_find_slot_at_beginning_in_ambiguous_values);
	ADD_TEST(test_binary_search_list__shall_find_slot_in_the_middle_in_ambiguous_values);
	ADD_TEST(test_binary_search_list__shall_find_slot_at_the_end_in_ambiguous_values);

	ADD_TEST(test_binary_search_list_limited__shall_find_first_item);
	ADD_TEST(test_binary_search_list_limited__shall_find_middle_item);
	ADD_TEST(test_binary_search_list_limited__shall_find_last_item);
	ADD_TEST(test_binary_search_list_limited__shall_find_first_item_in_ambiguous_values);
	ADD_TEST(test_binary_search_list_limited__shall_find_middle_item_in_ambiguous_values);
	ADD_TEST(test_binary_search_list_limited__shall_find_last_item_in_ambiguous_values);
	ADD_TEST(test_binary_search_list_limited__shall_find_slot_at_beginning);
	ADD_TEST(test_binary_search_list_limited__shall_find_slot_in_the_middle);
	ADD_TEST(test_binary_search_list_limited__shall_find_slot_at_the_end);
	ADD_TEST(test_binary_search_list_limited__shall_find_slot_at_beginning_in_ambiguous_values);
	ADD_TEST(test_binary_search_list_limited__shall_find_slot_in_the_middle_in_ambiguous_values);
	ADD_TEST(test_binary_search_list_limited__shall_find_slot_at_the_end_in_ambiguous_values);
	#else 
	ADD_TEST(test_binary_search_array__shall_find_first_item);
	ADD_TEST(test_binary_search_array__shall_find_middle_item);
	ADD_TEST(test_binary_search_array__shall_find_last_item);
	ADD_TEST(test_binary_search_array__shall_find_first_item_in_ambiguous_values);
	ADD_TEST(test_binary_search_array__shall_find_middle_item_in_ambiguous_values);
	ADD_TEST(test_binary_search_array__shall_find_last_item_in_ambiguous_values);
	ADD_TEST(test_binary_search_array__shall_find_slot_at_beginning);
	ADD_TEST(test_binary_search_array__shall_find_slot_in_the_middle);
	ADD_TEST(test_binary_search_array__shall_find_slot_at_the_end);
	ADD_TEST(test_binary_search_array__shall_find_slot_at_beginning_in_ambiguous_values);
	ADD_TEST(test_binary_search_array__shall_find_slot_in_the_middle_in_ambiguous_values);
	ADD_TEST(test_binary_search_array__shall_find_slot_at_the_end_in_ambiguous_values);
	#endif

	/* --- LINEAR SEARCH --- */
	#ifdef LIST_VARIANT
	ADD_TEST(test_linear_search_list__shall_find_first_item);
	ADD_TEST(test_linear_search_list__shall_find_middle_item);
	ADD_TEST(test_linear_search_list__shall_find_last_item);
	ADD_TEST(test_linear_search_list__shall_find_first_item_in_ambiguous_values);
	ADD_TEST(test_linear_search_list__shall_find_middle_item_in_ambiguous_values);
	ADD_TEST(test_linear_search_list__shall_find_last_item_in_ambiguous_values);
	ADD_TEST(test_linear_search_list__shall_not_find_missing_value);
	#else 
	ADD_TEST(test_linear_search_array__shall_find_first_item);
	ADD_TEST(test_linear_search_array__shall_find_middle_item);
	ADD_TEST(test_linear_search_array__shall_find_last_item);
	ADD_TEST(test_linear_search_array__shall_find_first_item_in_ambiguous_values);
	ADD_TEST(test_linear_search_array__shall_find_middle_item_in_ambiguous_values);
	ADD_TEST(test_linear_search_array__shall_find_last_item_in_ambiguous_values);
	ADD_TEST(test_linear_search_array__shall_not_find_missing_value);
	#endif


	run_tests();
	return 0;
}
