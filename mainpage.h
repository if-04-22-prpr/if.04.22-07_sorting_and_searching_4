/**
* @mainpage
* @section intro Introduction
*
* The implementation and evaluation of a collection of Sorting and Searching Algorithms.
* 
* @section objective Assignment Objective
*
* The target collection those algorithms are operation on, is an 'Array Backed List'. 
* This list shares (almost) the same interface (`list.h`) as the linked list from previous assignments
* but is implemented based on an array.
* Different sorting and searching algorithms are to be implemented using that list.
* A stopwatch shall be implemented that is used to measure the time a certain algorithm requires to sort or search.
* Eventually the measured times for defined number of list items and algorithms are compared.
* 
* **Configuration**
*
* The capacity of the backing array of the list is defined in `config.h` as `#define CAPACITY_INCREMENT`. 
* This value defines also the number of items for enlarging the backing array. This means, the array grows
* always in steps of `CAPACITY_INCREMENT` items.
*
* @section assignment Assignment
*
* In this assignment various sorting and search algorithms shall be implemented in multiple steps.
*
* **Step 1:**
*
* - Implemenation of an 'Array Backed List' by implementing files `array_backed_list.h`. 
* This file implements `list.h` using an array as underlying collection instead of a linked list. 
* In contrast to earlier assignments, the function `list_append(…)` was removed and `list_swap(…)` was added.
* The array shall have a certain capacity and need to be increased (with all consequences, such as of copying items) 
* if another item is added to a 'full' list.
* As a benefit, random access to items is fast, which is required by (most) sorting and searching algorithms.
* For implementation details read and follow the instructions in file `array_backed_list.c`.
*
* **Step 2:**
* 
* - Implementation of the infrastructure for selecting and using sorting and searching algorithms as well as
*   for measuring the time a certain algorithm takes for completing its operation.
* - Implementation of bubble sort algorithm
* - Implementation of insertion algorithm
* - Implementation of sorting criteria that can be applied as paramter to the algorithm (function pointer)
* 
*
* **Step 3:**
*
* - Implementation of merge sort algorithm
* - Extension of list as required
*
*
* **Step 4:**
*
* - Implementation of quick sort algorithm
* - Implementation of linear search algorithm
* - Implementation of binary search algorithm
* - Implementation of insertion sort algorithm using binary search
*
* @section instructions Working Instructions
*
* The library 'allocator' is provided for memory allocation functionality that integrates with unit testing. Behind the facade,
* allocats memory dynamically similar to `malloc`. Allocated memory must be freed when it is not used anymore. The 'allocator'
* library must be used for memory alloction operations, otherwise unit tests will fail.
* 
* **Step 1:**
*
* -# Implement 'array_backed_list.c' against interface indirectly declared in 'list.h':
*    Make the program and tests compile: Implement all functions in all relevant files declared in the headers 
*    EMTPY (return nothing, 0, false, ... as required).
*   - All unit tests shall run but FAIL after this step
*   - **--COMMIT--**
* -# Implement the empty functions one by one to make the unit tests.
*   - Because most unit tests depends on `list_obtain(…)`, `list_release(…)`, `list_is_valid(…)`, 
*     `list_is_empty(…)`, `list_insert(…)`, and `list_get_size(…)` it makes sense to implement those
*     functions in one step.
*   - The purpose of a function is specified as API documentation within the header files.
*   - Obey comments in source files. Run the unit tests frequently and fix failures.
*   - **--COMMIT-- after each implemented function.**
*
* **Step 2:**
* -# Based on 'array_backed_list' from step 1. If you don't own an implementation of that list (for good reasons), then:
*    -# Implement the sorting algorithms based on a large, simple array (length: >= 2^16, see below).
*    -# Comment the `#define LIST_VARIANT` in `config.h` to enable the functions using arrays and disable those for the list.
*    -# **Note** Only one variant (list OR array) need to be implemented.
*    
* -# Implement all functions defined by the files below empty to make the program compile.
*    **--COMMIT--**
* -# `stopwatch.[h|c]` Implement the `stopwatch`. The stopwatch is required to measure the runtime of algorithms
*    or execution steps. Details about the implementation of the stopwatch can be found in `stopwatch.c`.
*    Run the unit tests targeting stop watch functionality and make them green.
*    **--COMMIT--**
* -# `sorting_criteria.[h|c]`: Implement the sorting criteria function and the define the function pointer type for those functions.
*    Run the unit tests targeting the sorting criteria functions and make them green.
*    **--COMMIT--**
* -# `bubble_sort.[h|c]`: Implement the bubble sort algorithm.
*    Run the unit tests targeting the bubble sort algorithm and make them green.
*    **--COMMIT--**
* -# `insertion_sort.[h|c]`: Implement the insertion sort algorithm.
*    Run the unit tests targeting the insertion sort algorithm and make them green.
*    **--COMMIT--**
* -# `sorting.[h|c]`: Implement the support functions for the sorting application. These functions include initialization,
*    printing (optional), and selection of the desired sorting algorithm. It also declares an enumeration of all supported
*    sorting algorithms. Details regarding the implementation of those functions are mentioned in the top section of `sorting.c`.
*    Run the unit tests targeting the sorting support function  and make them green.
*    **--COMMIT--**
* -# `timed_sorting_main_driver.c`: Implement the body of the measurement application. Organize the main application file as wanted.
*     The application shall measure the time for sorting data of different size with all supported algorithms for the average, the best, 
*     and the worst case. In addition, it shall measure the time required for setting up and tearing down the data structure.
*
*     For each supported sorting algorithm defined in `sorting.h`, starting with an item count of 1:
*         -# Obtain the data structure (list or array) and initialize it randomly using the according function of `sorting.h`.
*            Measure the time for this step as 'Init' time.
*         -# Sort the data using the selected algorithm and measure the time for this step as 'Sort Avg' time.
*         -# Sort the data using the selected algorithm again (in the same direction) and measure the time for this step as 'Sort Best' time.
*         -# Sort the data using the selected algorithm in reverse direction and measure the time for this step as 'Sort Worst' time.
*         -# Release the data structure (if applicable) and measure the time for this step as 'Release' time.
*         -# Print the measured times as described below.
*         -# Double the number of items to sort and repeat at step a) as long the item counter is less than 20k or 50k item (depending on your system).
*
*    **--COMMIT--**
*
*    The print outs as described above shall produce a table as shown below. 
*    The format pattern for the item count should be `%7d` and `%10.1f` for time values. Pipes `|` herein are not part of the format, 
*    they are just reqired for markdown. Such a data table can be examined further in a spreadsheet application such as MS Excel.
*    Describe your observations, verify the runtime complexity based on your time measurements.
*    
*    **Note:**: You can take time measurements using different value for `CAPACITY_INCREMENT`. Only `Init` time should differ significantly.
*
* | Algorithm;     |   Items;| Sort_Random;| Sort_Sorted;| Sort_Reverse;|       Init;|    Release|
* |:---------------|--------:|------------:|------------:|-------------:|-----------:|----------:|
* | Bubble Sort;   |       1;|         1.0;|         1.0;|          1.0;|        5.0;|        1.0|
* | Bubble Sort;   |       2;|         0.0;|         0.0;|          1.0;|        3.0;|        0.0|
* | Bubble Sort;   |       4;|         1.0;|         0.0;|          1.0;|        3.0;|        1.0|
* | Bubble Sort;   |       8;|         1.0;|         0.0;|          1.0;|        3.0;|        0.0|
* | Bubble Sort;   |      16;|         2.0;|         0.0;|          3.0;|        3.0;|        1.0|
* | Bubble Sort;   |      32;|        10.0;|         1.0;|         10.0;|       17.0;|        1.0|
* | Bubble Sort;   |      64;|        36.0;|         1.0;|         40.0;|        4.0;|        1.0|
* | Bubble Sort;   |     128;|       143.0;|         2.0;|        156.0;|        5.0;|        1.0|
* | Bubble Sort;   |     256;|       622.0;|         3.0;|       1676.0;|        7.0;|        1.0|
* | Bubble Sort;   |     512;|      2697.0;|         7.0;|       2855.0;|       14.0;|        1.0|
* | Bubble Sort;   |    1024;|     12267.0;|        12.0;|      11984.0;|       23.0;|        2.0|
* | Bubble Sort;   |    2048;|     43619.0;|        25.0;|      44301.0;|       42.0;|        2.0|
* | Bubble Sort;   |    4096;|    169480.0;|        49.0;|     181360.0;|       78.0;|        2.0|
* | Bubble Sort;   |    8192;|    667259.0;|        98.0;|     714083.0;|      157.0;|        1.0|
* | Bubble Sort;   |   16384;|   2683571.0;|       350.0;|    2837608.0;|      408.0;|       33.0|
* | Bubble Sort;   |   32768;|  10263822.0;|       571.0;|   11325744.0;|     1879.0;|       31.0|
* | Insertion Sort;|       1;|         1.0;|         1.0;|          0.0;|      218.0;|        0.0|
* | Insertion Sort;|       2;|         0.0;|         0.0;|          1.0;|        2.0;|        1.0|
* | Insertion Sort;|       4;|         0.0;|         0.0;|          1.0;|        2.0;|        1.0|
* | Insertion Sort;|       8;|         1.0;|         0.0;|          1.0;|        2.0;|        1.0|
* | Insertion Sort;|      16;|         2.0;|         1.0;|          2.0;|        2.0;|        0.0|
* | Insertion Sort;|      32;|         5.0;|         1.0;|          7.0;|        2.0;|        0.0|
* | Insertion Sort;|      64;|        15.0;|         2.0;|         29.0;|        2.0;|        0.0|
* | Insertion Sort;|     128;|        60.0;|         3.0;|        114.0;|        4.0;|        1.0|
* | Insertion Sort;|     256;|       219.0;|         5.0;|        583.0;|        6.0;|        1.0|
* | Insertion Sort;|     512;|      1010.0;|        12.0;|       2026.0;|       11.0;|        1.0|
* | Insertion Sort;|    1024;|      4066.0;|        28.0;|       8800.0;|       32.0;|        2.0|
* | Insertion Sort;|    2048;|     16718.0;|        80.0;|      33491.0;|       35.0;|        2.0|
* | Insertion Sort;|    4096;|     64592.0;|       205.0;|     129536.0;|       69.0;|        2.0|
* | Insertion Sort;|    8192;|    259646.0;|       670.0;|     524065.0;|      142.0;|        2.0|
* | Insertion Sort;|   16384;|   1094843.0;|      2327.0;|    2075412.0;|      360.0;|       24.0|
* | Insertion Sort;|   32768;|   4188706.0;|     10525.0;|    8367830.0;|     1677.0;|       34.0|
*
* **Step 3:**
* -# Copy all header and source files that need to be implemented in this assignment but have been already
*    developed in earlier steps (esp. step 2) from YOUR solution to this assignment.
*    Do not copy unit tests!
*    **--COMMIT--**
* -# Based on 'array_backed_list' from step 2. If you don't own an implementation of that list (for good reasons), then:
*    -# Implement the sorting algorithms based on a large, simple array (length: >= 2^16, see below).
*    -# Comment the `#define LIST_VARIANT` in `config.h` to enable the functions using arrays and disable those for the list.
*    -# **Note** Only one variant (list OR array) need to be implemented.
*    
* -# Implement all functions defined by the file below empty to make the program compile.
*    **--COMMIT--**
* -# `array_backed_list.c`: (list variant only)
*     -# Implement the additional functions as defined in `list.h`
*        - `list_append`
*        - `list_split`
*        - `list_transfer_head`
*    **--COMMIT--**
* -# `merge_sort.[h|c]`: Implement the merge sort algorithm.
*    Run the unit tests targeting the merge sort algorithm and make them green.
*    **--COMMIT--**
* -# `sorting.[h|c]`: Extend the functions that delegates to different sorting algorithms to support MERGE_SORT.
*    Run the unit tests targeting the sorting support function  and make them green.
*    **--COMMIT--**
* -# Run the application. The output shown above for step 2 should be extended for Merge Sort.
* 
* **Step 4:**
* -# Copy all header and source files that need to be implemented in this assignment but have been already
*    developed in earlier steps (esp. step 3) from YOUR solution to this assignment.
*    Do not copy unit tests!
*    **--COMMIT--**
* -# Based on 'array_backed_list' from step 3. If you don't own an implementation of that list (for good reasons), then:
*    -# Implement the sorting algorithms based on a large, simple array (length: >= 2^16, see below).
*    -# Comment the `#define LIST_VARIANT` in `config.h` to enable the functions using arrays and disable those for the list.
*    -# **Note** Only one variant (list OR array) need to be implemented.
*    
* -# Implement all functions defined by the file below empty to make the program compile.
*    **--COMMIT--**
* -# `quick_sort.[h|c]`: Implement the quick sort algorithm.
*    Run the unit tests targeting the quick sort algorithm and make them green.
*    **--COMMIT--**
* -# `insertion_sort_binary_search.[h|c]`: Implement the insertion sort algorithm that uses binary search for finding the insert position.
*    The insertion sort algorithm implemented in step 2 can be reused and modified.
*    Run the unit tests targeting the insertion sort with binary search algorithm and make them green.
*    **--COMMIT--**
* -# `sorting.[h|c]`: Extend the functions that delegates to different sorting algorithms to support QUICK_SORT and INSERTION_SORT_BINARY_SEARCH.
*    Run the unit tests targeting the sorting support function and make them green.
*    **--COMMIT--**
* -# `linear_search.[h|c]`: Implement the linear search algorithm.
*    Run the unit tests targeting the linear search algorithm and make them green.
*    **--COMMIT--**
* -# `binary_search.[h|c]`: Implement the binary search algorithm.
*    Run the unit tests targeting the binary search algorithm and make them green.
*    **--COMMIT--**
* -# `timed_sorting_main_driver.c`: Extend the application with measurement for search algorithms. 
*     Organize the main application file as wanted.
*     In addition the application shall measure the time for searching a value using linear search and binary search within 
*     a long (> 16k items) list or array. The time for searching every Xth item that is contained in the list or array shall
*     be measured for each search algorithm, X may be ~100.
*
*     **Note:** Especially for binary search, measuring one search execution may result in values beyond measurable range.
*               Therefore the time measurement of a single item shall invoke the search function Y times (Y >= 10).
*               The accumulated measured result need them be divided by Y (time = measured_time/Y).
*
*     The print-out for these measurements may look like:
* | Algorithm;     |   Index;| Time;|
* |:---------------|--------:|-----:|
* | Bubble Sort;   |       1;|  1.0;|
* | Linear Search; |       0;|  0.1;|
* | Binary Search; |       0;|  0.1;|
* | Linear Search; |     128;|  0.5;|
* | Binary Search; |     128;|  0.2;|
* | Linear Search; |     256;|  0.7;|
* | Binary Search; |     256;|  0.1;|
* | Linear Search; |     384;|  1.0;|
* | Binary Search; |     384;|  0.2;|
* | Linear Search; |     512;|  1.2;|
* | Binary Search; |     512;|  0.1;|
*
* -# Run the application. The output shown above for step 2 should be extended for Quick Sort and Insertion Sort with Binary Search
*    as well as with the measurements for search algorithms as shown above.
* 
*
* @section notes Notes
* -# `general.h` contains macros for finding the minimum, maximum, and absolute value 
* -# make cleantest: This new make target for clearing the console, building, and running unit test is available.
* -# Sometimes changes are not properly detected by incremental builds. If something very strange 
*    happens during compilation, try to run `make clean` followed by `make` to start a clean build.
*    This approach is also recommended after everthing is done, because some compiler warning appears
*    only in clean builds. 
*/