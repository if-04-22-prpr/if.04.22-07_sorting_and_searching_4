/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for the stopwatch
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions of the stopwatch.
 * ----------------------------------------------------------
 */

#include "test_stopwatch.h"

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "shortcut.h"
#include "config.h"

#include "stopwatch.h"

static double measure_test_load() {
    clock_t start = clock();
    for(int i = 1; i < 500000; i++) {
        sqrt(i * 2.0);
    }
    return ((double)(clock() - start) / CLOCKS_PER_SEC) * 1000.0;
}

/* ------------------------------------------------------------------- */

TEST(test_stopwatch_is_active__shall_provide_running_state) {
    ASSERT_FALSE(stopwatch_is_active(), MSG("Expected initially inactive stopwatch"));
    stopwatch_stop();
    ASSERT_FALSE(stopwatch_is_active(), MSG("Expected still inactive stopwatch"));
    stopwatch_start();
    ASSERT_TRUE(stopwatch_is_active(), MSG("Expected active stopwatch"));
    stopwatch_stop();
    ASSERT_FALSE(stopwatch_is_active(), MSG("Expected inactive stopwatch"));
    stopwatch_start();
    ASSERT_TRUE(stopwatch_is_active(), MSG("Expected again active stopwatch"));
    stopwatch_resume();
    ASSERT_TRUE(stopwatch_is_active(), MSG("Expected still active stopwatch"));
    stopwatch_stop();
    ASSERT_FALSE(stopwatch_is_active(), MSG("Expected inactive stopwatch for the 2nd time"));
    stopwatch_resume();
    ASSERT_TRUE(stopwatch_is_active(), MSG("Expected active resumed stopwatch"));
    stopwatch_stop();
    ASSERT_FALSE(stopwatch_is_active(), MSG("Expected finally inactive stopwatch"));
}

TEST(test_stopwatch_start__shall_provide_elapsed_time) {
    stopwatch_start();
    double load_time_1 = measure_test_load();
    double el_time_1 = stopwatch_get_elapsed_time() / 1000.0;
    double load_time_2 = measure_test_load();
    double el_time_2 = stopwatch_get_elapsed_time() / 1000.0;
    stopwatch_stop();

    ASSERT_TRUE(el_time_1 > 0.0, MSG("Expected that time proceeded for 1st measurement"));
    ASSERT_EQUALS_TOLERANCE_STR(load_time_1, el_time_1, 0.04, MSG("Expected that time proceeded to %.3f, but is %.3f", load_time_1, el_time_1));
    ASSERT_TRUE(el_time_2 > el_time_1, MSG("Expected that time proceeded for 2nd measurement"));
    ASSERT_EQUALS_TOLERANCE_STR(load_time_1 + load_time_2, el_time_2, 0.08, MSG("Expected that time proceeded to %.3f, but is %.3f", load_time_1 + load_time_2, el_time_2));
}

TEST(test_stopwatch_start_stop__shall_provide_elapsed_time) {
    stopwatch_start();
    double load_time_1 = measure_test_load();
    stopwatch_stop();
    double el_time_1 = stopwatch_get_elapsed_time() / 1000.0;
    measure_test_load();
    double el_time_2 = stopwatch_get_elapsed_time() / 1000.0;
    ASSERT_TRUE(el_time_1 > 0.0, MSG("Expected that time proceeded"));
    ASSERT_EQUALS_TOLERANCE_STR(load_time_1, el_time_1, 0.04, MSG("Expected that time proceeded to %.3f, but is %.3f", load_time_1, el_time_1));
    ASSERT_EQUALS_TOLERANCE_STR(el_time_1, el_time_2, 0.001, MSG("Expected that time is kept as %.3f, but is %.3f", el_time_1, el_time_2));
}

TEST(test_stopwatch_start_stop_resume__shall_provide_elapsed_time) {
    stopwatch_start();
    double load_time_1 = measure_test_load();
    stopwatch_stop();
    double el_time_1 = stopwatch_get_elapsed_time() / 1000.0;
    measure_test_load();
    double el_time_2 = stopwatch_get_elapsed_time() / 1000.0;
    stopwatch_resume();
    double load_time_2 = measure_test_load();
    stopwatch_stop();
    double el_time_3 = stopwatch_get_elapsed_time() / 1000.0;

    ASSERT_TRUE(el_time_1 > 0.0, MSG("Expected that time proceeded"));
    ASSERT_EQUALS_TOLERANCE_STR(load_time_1, el_time_1, 0.04, MSG("Expected that time proceeded to %.3f, but is %.3f", load_time_1, el_time_1));
    ASSERT_EQUALS_TOLERANCE_STR(el_time_1, el_time_2, 0.001, MSG("Expected that time is kept as %.3f, but is %.3f", el_time_1, el_time_2));
    ASSERT_EQUALS_TOLERANCE_STR(load_time_1 + load_time_2, el_time_3, 0.04, MSG("Expected that time proceeded to %.3f, but is %.3f", load_time_1 + load_time_2, el_time_3));
}
