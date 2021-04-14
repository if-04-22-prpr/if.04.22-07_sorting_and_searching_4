/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: S07
 * Title:			Stopwatch
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * A stop watch to measure CPU time
 * ----------------------------------------------------------
 */
#ifndef ___STOPWATCH_H
#define ___STOPWATCH_H

/**
 * Functions to measure the processor time needed for a section of code. Usage
 * <pre>
 * <code>
 * stopwatch_start();
 * ...
 * // some code to be measured
 * stopwatch_stop();
 * double elapsed1 = stopwatch_get_elapsed_time(); // given in seconds
 * ...
 * stopwatch_resume();
 * // some more code to be measured
 * double elapsed2 = stopwatch_get_elapsed_time(); // elapsed2 is time in seconds from start_stopwatch() on
 * ...
 * // some more code to be measured
 * stop_stopwatch();
 * double elapsed3 = stopwatch_get_elapsed_time(); // time between start_stopwatch() and stop_stopwatch();
 * </code>
 * </pre>
 *
 * Care must be taken that we measure CPU time! Check out the function clock() and the constant
 * CLOCKS_PER_SEC from time.h in order to implement the functions correctly.
 */

/**
 * Starts taking the time. This function always starts at 0.
 */
void stopwatch_start();

/**
 * Stops or pauses taking the time. Time measurement can be resumed 
 * via `stopwatch_resume`.
 */
void stopwatch_stop();

/**
 * Resumes taking the time. The previously measured time value is
 * used as start value.
 */
void stopwatch_resume();

/**
 * Determines whether or not the stopwatch takes the time.
 * @return True if the stopwatch is measuring, false otherwise.
 */
bool stopwatch_is_active();

/**
 * The measured time in microseconds.
 * 
 * @return Either the processor time elapsed since start_stopwatch() has been called or
 * the processor time elapsed between the calls of start_stopwatch() and stop_stopwatch().
 */
double stopwatch_get_elapsed_time();

#endif
