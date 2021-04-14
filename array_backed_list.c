/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: S07
 * Title:			Array backed List implementation
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Implementation of an array backed list.
 * ----------------------------------------------------------
 */

/*
  Implementation notes:

  1) The 'ListData' struct of this linked list SHALL have
     - a buffer for the payload data (array of integer), 
     - the capacity of the buffer (length of the array)
     - and the size of the list (number actual element in the list)
    as members!

  2) List allocation: 
     Use functions `mem_alloc(…)` and `mem_free(…)`
     declared in `allocator.h`. DO NOT use `malloc(…)` and `free(…)` directly
     as unit tests will fail.

    Note:
     a) `list_obtain` shall allocate only the list data, but NOT the payload buffer
     b) The payload buffer shall be allocated when a value is inserted the first time.
        The payload buffer shall be increased if an additional item shall be inserted 
        (via one of the insert functions) no capacity is left. All  values contained in the list
        shall be copied into the increased buffer.
        Initial allocation of the payload buffer and increasing the payload buffer is actually
        the same case, because the initial capacity is 0 and therefore no capacity is left.
        The payload buffer shall be increased by `CAPACITY_INCREMENT` (`config.h`) items.        
     c) `list_clear` shall NOT free the payload buffer. Setting the size to 0 is sufficient.
     d) `list_release` shall free the payload buffer, if it was allocated.

  3) Use 'limits.h' to get maximum and minimum values for numeric types, if needed.

*/

#include "array_backed_list.h"

/* add includes as needed */

#include "config.h"
#include "allocator.h"


/** The implementation of list data: payload-buffer, capacity, size */
struct IntListData {
};

/* ===================================================================== */
/* private list functions */

/** 
 * Enlarges the backing array by the given amount of items. 
 * Hint: memcpy may be used to copy all bytes(!) from the existing to the new buffer
 */
static void increase_buffer(IntList list, unsigned int additional_capacity) {
}

/* ===================================================================== */
