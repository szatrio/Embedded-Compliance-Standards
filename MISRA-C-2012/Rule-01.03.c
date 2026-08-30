#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 1.3
 * Rule: There shall be no occurrence of undefined or critical unspecified behavior.
 */

/* --- NON-COMPLIANT --- */
/* Common Undefined Behavior scenarios. */
void undefined_behavior_bad(uint16_t *p_data) {
    uint16_t val;
    
    /* Violation: Dereferencing a NULL pointer is undefined behavior. */
    // val = *p_data; 
    
    /* Violation: Integer overflow on signed types is undefined behavior in C. */
    int16_t x = 32767;
    x = x + 1; 
    
    /* Violation: Accessing an array out of bounds. */
    uint16_t arr[5];
    val = arr[10]; 
}

/* --- MISRA COMPLIANT --- */
/* Always validate inputs and bounds to ensure defined behavior. */
void defined_behavior_good(uint16_t *p_data) {
    uint16_t val = 0U;

    /* Compliant: Always check for NULL before dereferencing. */
    if (p_data != NULL) {
        val = *p_data;
    }
}