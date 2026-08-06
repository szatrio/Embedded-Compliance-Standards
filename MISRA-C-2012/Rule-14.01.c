#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 14.1
 * Rule: A loop counter shall not have essentially floating type.
 */
void test_compliance_14_1(void) {

    float step = 0.1f;
    float current_val = 0.0f;
    uint32_t loop_counter = 0U;

    /* --- NON-COMPLIANT --- */
    /* Using a floating-point variable as a loop counter. Accumulated rounding 
       errors (IEEE 754 precision issues) can cause an unpredictable number 
       of iterations or lead to an infinite loop. */
    for (float f = 0.0f; f < 1.0f; f += 0.1f) {
        /* Loop logic */
    }


    /* --- MISRA COMPLIANT --- */
    /* Use an integer loop counter to guarantee a deterministic iteration count, 
       then derive the floating-point value explicitly inside the loop body. */
    for (loop_counter = 0U; loop_counter < 10U; loop_counter++) {
        current_val = (float)loop_counter * step;
        (void)current_val; /* Prevents unused variable compiler warning */
    }
}