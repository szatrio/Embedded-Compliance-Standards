#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 15.7
 * Rule: All if ... else if constructs shall be terminated with an else statement.
 */
void test_compliance_15_7(uint8_t system_mode) {
    
    uint8_t output_signal = 0U;

    /* --- NON-COMPLIANT --- */
    /* The construct ends with an 'else if'. If 'system_mode' is neither 1 nor 2, 
       the execution passes through without any explicit handling, which is defensive risk. */
    /* if (system_mode == 1U) {
        output_signal = 10U;
    } else if (system_mode == 2U) {
        output_signal = 20U;
    } 
    */


    /* --- MISRA COMPLIANT --- */
    /* Even if the final 'else' block is empty or contains an error handler, 
       it must be present to demonstrate that all execution paths were considered. */
    if (system_mode == 1U) {
        output_signal = 10U;
    } else if (system_mode == 2U) {
        output_signal = 20U;
    } else {
        /* Defensive programming: Handle unexpected modes or do nothing explicitly */
        output_signal = 0U; 
    }
}
