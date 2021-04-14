/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: S07
 * Title:			List Interface
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * The declaration of a list abstract data type.
 * ----------------------------------------------------------
 */

#ifndef ___LIST__H
#define ___LIST__H

#include <stdbool.h>

#include "list_types.h"

/**
 * Obtains ('creates') and provides a 'new' list instance.
 * Any list obtained via this function MUST be released using
 * function `release_list()`.
 * 
 * Note: This function does not make any assumptions 
 * about how list components, esp. nodes, are allocated.
 * 
 * @return The list instance or 0, if no list could by instantiated.
 */
IntList list_obtain();

/**
 * Releases a list that was obtained earlier via function `obtain_list`.
 * Released lists MUST NOT be used anymore.
 * 
 * Note: The implementation of this function does not make any assumptions
 * about the allocation method of list elements, but MUST match the implementation
 * of function `obtain_list` as its inverse function.
 * 
 * @param p_list The pointer to the list to release. The value of the pointer
 * is set to 0, if the list was successfully released, otherwise it is left untouched.
 */
void list_release(IntList* p_list);

/**
 * Determines whether or not the given list is valid.
 * 
 * @param list The list to evaluate.
 * @return `True` if the list is valid, false otherwise.
 */
bool list_is_valid(IntList list);

/**
 * Determines whether or not the list contains at least one item.
 * 
 * @param list The list to evaluate.
 * @return `False` if the list contains one or more items, `true` otherwise.
 */
bool list_is_empty(IntList list);

/**
 * Provides the number of values stored in the list.
 * 
 * @param list The list to evaluate.
 * @return The number of values the list contains.
 */
int list_get_size(IntList list);

/**
 * Determines whether or not the list given list contains the queried value
 * at least once.
 * 
 * @param list The list to query.
 * @param value The value.
 * @return `True` if the list contains at least one instance of the value, 
 * `false ` otherwise.
 */
bool list_contains(IntList list, int value);

/**
 * Provides the value stored in the list at the given position.
 * 
 * @param list The list from which the value shall be retrieved.
 * @param index The zero-based position index of the value to retrieve.
 * @return The value stored at the given position or 0, if the position
 * is not available.
 */
int list_get_at(IntList list, unsigned int index);

/**
 * Inserts the given value at the end of the given list.
 * 
 * @param list The list to which the value shall be appended.
 * @param value The value to append to the list.
 */
void list_insert(IntList list, int value);

/**
 * Inserts the given value at the indexed position in a way the 
 * the inserted value is on that position. The index is
 * - similar to arrays - zero-based. If the the list is shorter
 * than the indexed position, the value is inserted at the end
 * of the list.
 * 
 * @param list The list into which the value shall be appended.
 * @param index The position index of the value to insert.
 * @param value  The value to insert.
 */
void list_insert_at(IntList list, unsigned int index, int value);

/**
 * Removes the first occurrance of `value` from the given list.
 * If the list does not contain that value, the list shall not
 * be modified.
 * 
 * @param list The list from which the given value shall be removed.
 * @param value The value to remove from the list.
 */
void list_remove(IntList list, int value);

/**
 * Removes all occurrances of `value` from the list.
 * If the list does not contain that value, the list shall not
 * be modified.
 * 
 * @param list The list from which all occurrances of `value` shall be removed.
 * @param value The `value` to remove throughout the list.
 */
void list_remove_all(IntList list, int value);

/**
 * Removes the value at the indexed position from the given list
 * and provides that value. If the list does not have a value
 * at that position, the list remains unmodified.
 * 
 * @param list The list from which the value at the given index shall be returned.
 * @param index The zero-based index of the value to return.
 * @return The removed value or 0 in case of errors.
 */
int list_remove_at(IntList list, unsigned int index);

/**
 * Appends the `list_to_append` at the end of the given `list`.
 * The appended list is empty afterwards, because all nodes of that list
 * have been transferred to `list`.
 * 
 * @param list The list that receives the other list.
 * @param list_to_append The list that is appended to `list`.
 */
void list_append(IntList list, IntList list_to_append);

/**
 * Swaps the values at the given indexes, so that value at fst_idx becomes
 * the value at snd_idx and vice versa. The invocation is ignored, if the 
 * list is invalid or at least one of the given indexes is out of range.
 * 
 * @param list The list to manipulate
 * @param fst_idx The index of the first item to swap.
 * @param snd_idx The index of the second item to swap.
 */
void list_swap(IntList list, unsigned int fst_idx, unsigned int snd_idx);

/**
 * Splits the given `list` into a `left` and `right` part at the given `split_idx`.
 * The `left` list contains the items of `list` from head to `split_idx - 1` rendering
 * the size of the left part equal to `split_idx`. The `right` list contains
 * the items of `list` from originally `split_idx` to tail.
 * 
 * If `split_idx` is larger than the size of `list`, all items of `list` 
 * are moved to `left`, leaving the `right` list empty.
 * 
 * If a target list (`left`, `right`) is not empty, the nodes that are received from
 * `list` are appended.
 * 
 * If any of the given lists is invalid, the invocation is ignored.
 * 
 * @param list The list to split.
 * @param left The left part of the original list.
 * @param right The right part of the original list.
 * @param split_idx The index of the node of `list` that becomes the head of `right` list.
 */
void list_split(IntList list, IntList left, IntList right, unsigned int split_idx);

/**
 * Transfers the first node (the 'head') of the given `list` as last node ('tail') 
 * of the target list.
 * 
 * If any of the given lists is invalid or the source list is empty, the invocation is ignored.
 * 
 * @param list The list from which the `head` is transferred to `target_list`.
 * @param target_list The list that receives the head of `list`.
 */
void list_transfer_head(IntList list, IntList target_list);

/**
 * Clears the given list by removing all values from the list.
 * 
 * @param list The list to clear.
 */
void list_clear(IntList list);

#endif
