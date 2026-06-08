#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 15.6
 * Rule:The body of an iteration-statement or a selection-statement shall be a compound-statement.
 */
void test_compliance_15_6(int32_t system_error_code) {

    /* Bad Practice (Non-Compliant) */
    // if (system_error_code != 0)
    //     trigger_alarm(); // Dangerous if another line is added later

    /* Good Practice (MISRA Compliant) */
    if (system_error_code != 0) {
        /* Always wrap in braces for predictability */
        // trigger_alarm();
    } else {
        /* Even an empty or single line else must have braces */
    }
}