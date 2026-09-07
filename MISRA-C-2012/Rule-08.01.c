#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.1
 * Rule: Types shall be explicitly specified.
 */

/* --- NON-COMPLIANT --- */
/* Violation: Function does not have a return type specified. 
   The compiler defaults to 'int', which is prohibited by MISRA. */
my_function(void) { 
    return 1;
}

/* Violation: Variable 'x' has no specified type. */
static x = 10; 

/* --- MISRA COMPLIANT --- */
/* Compliant: Return type 'void' is explicitly specified */
void my_function_good(void) {
    /* ... */
}

/* Compliant: Return type 'uint32_t' is explicitly specified */
uint32_t calculate_value(void) {
    return 100U;
}

/* Compliant: Variable 'x' has an explicit type 'int32_t' */
static int32_t x = 10;