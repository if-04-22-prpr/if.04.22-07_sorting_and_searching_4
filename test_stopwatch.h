/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Unit Tests for the stopwatch implementation
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions of the stopwatch.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_STOPWATCH_H
#define ___TEST_STOPWATCH_H

#include "shortcut.h"

TEST(test_stopwatch_is_active__shall_provide_running_state);
TEST(test_stopwatch_start__shall_provide_elapsed_time);
TEST(test_stopwatch_start_stop__shall_provide_elapsed_time);
TEST(test_stopwatch_start_stop_resume__shall_provide_elapsed_time);

#endif
