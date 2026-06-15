#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 17.6
 * Rule: The declaration of an array parameter shall not contain 
 * the static keyword between the [ ].
 */

/* --- NON-COMPLIANT --- */
/* Using 'static' inside array parameters is prohibited by MISRA. */
void process_array_bad(uint16_t arr[static 10U]) {
    /* Violation: 'static' keyword inside [ ] is not allowed. */
    (void)arr[0];
}

/* --- MISRA COMPLIANT --- */
/* Use standard array notation or pointer notation. */
void process_array_good(uint16_t arr[], uint16_t size) {
    /* Compliant: Standard array parameter declaration. 
       Check the size manually to prevent buffer overflow. */
    if (size >= 10U) {
        (void)arr[0];
    }
}