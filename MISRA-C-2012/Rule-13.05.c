#include <stdint.h>
#include <stdbool.h>

/* Global state for demonstration */
static uint16_t g_status_flag = 0U;

static uint16_t get_next_sensor_val(void) {
    g_status_flag++; /* Persistent side effect */
    return g_status_flag;
}

/* --- NON-COMPLIANT --- */
void test_non_compliant(bool condition, uint16_t counter) {
    /* * Violation: Increment 'counter' only happens if 'condition' is true. 
     * Side effect in RH operand of '&&'.
     */
    if (condition && (++counter > 5U)) {
        /* Logic */
    }

    /* * Violation: Function call modifying global state on RH operand of '||'.
     * 'get_next_sensor_val()' will NOT be called if 'condition' is true!
     */
    if (condition || (get_next_sensor_val() > 10U)) {
        /* Logic */
    }
}

/* --- MISRA COMPLIANT --- */
void test_compliant(bool condition, uint16_t counter) {
    bool is_counter_valid = false;
    uint16_t sensor_val = 0U;

    /* Compliant: Move side-effects out of logical expression */
    counter++;
    is_counter_valid = (counter > 5U);

    if (condition && is_counter_valid) {
        /* Logic */
    }

    /* Compliant: Explicitly execute side-effect before logical operation */
    sensor_val = get_next_sensor_val();

    if (condition || (sensor_val > 10U)) {
        /* Logic */
    }
}