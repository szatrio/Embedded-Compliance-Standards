#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 17.4
 * Rule: All exit paths from a function with non-void return type 
 * shall have an explicit return statement with an expression.
 */

/* --- NON-COMPLIANT --- */
/* If 'input' is 0, the function finishes without hitting a 'return'. */
uint16_t calculate_status_bad(uint16_t input) {
    if (input > 10U) {
        return 1U;
    }
    /* Violation: If input <= 10, the function reaches the end 
       without an explicit return statement. */
}

/* --- MISRA COMPLIANT --- */
/* Every possible branch ends with an explicit return. */
uint16_t calculate_status_good(uint16_t input) {
    uint16_t status = 0U;

    if (input > 10U) {
        status = 1U;
    } else {
        status = 0U;
    }
    
    /* Compliant: Explicit return for all paths. */
    return status;
}