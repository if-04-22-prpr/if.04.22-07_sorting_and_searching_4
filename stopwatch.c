/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: S07
 * Title:			Stopwatch
 * Author:			*/<your name>;/*
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a simple stopwatch
 *-----------------------------------------------------------------------------
*/
#include <time.h>
#include <stdbool.h>

#include "stopwatch.h"

/**
 * Implementation hints:
 * 
 * time functions:
 *   are provided by `time.h`
 *   use function `clock()` to get the current `ticks`
 *   `ticks` are of type `clock_t`
 *   use `CLOCKS_PER_SEC` to calculate the time in seconds from ticks
 *     -> seconds = ticks / CLOCK_PER_SEC
 *   microseconds are s * 10^-6
 */
