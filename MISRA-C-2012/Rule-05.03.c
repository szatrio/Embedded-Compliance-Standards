#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 5.3
 * Rule: An identifier declared in an inner scope shall not hide 
 * an identifier declared in an outer scope.
 */

/* --- NON-COMPLIANT --- */
void shadowing_bad(void) {
    uint16_t status = 0U; /* Variable in outer scope */

    if (1) {
        /* Violation: 'status' declared here hides the 'status' from the outer scope */
        uint16_t status = 1U; 
        
        /* Modifying 'status' here only affects the inner variable, 
           leaving the outer 'status' unchanged. */
    }
}

/* --- MISRA COMPLIANT --- */
void shadowing_good(void) {
    uint16_t outer_status = 0U;

    if (1) {
        /* Compliant: Distinct names prevent shadowing and improve clarity */
        uint16_t inner_status = 1U; 
        outer_status = inner_status;
    }
}