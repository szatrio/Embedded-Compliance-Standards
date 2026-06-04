#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 17.3
 * Rule: The freshness of the value of a function parameter shall not be modified.
 */

/* --- NON-COMPLIANT --- */
/* Modifying the parameter 'input_val' directly changes the local value,
   which can lead to confusion if the original intent was to keep it intact. */
void process_value_bad(uint16_t input_val) {
    input_val = input_val + 10U; /* Violation: Modifying parameter directly */
    /* ... rest of logic ... */
}

/* --- MISRA COMPLIANT --- */
/* Use a local variable to perform calculations. This keeps the 
   original 'input_val' unchanged and clearly defines the scope of changes. */
void process_value_good(uint16_t input_val) {
    uint16_t local_val = input_val;
    
    local_val = local_val + 10U; /* Safely modify local copy */
    /* ... rest of logic ... */
}
