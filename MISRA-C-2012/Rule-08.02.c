#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.2
 * Rule: Function types shall be in prototype form with named parameters.
 */

/* --- NON-COMPLIANT --- */
/* Violation: Function prototype is not provided, or parameters are not named. 
   "K&R" style is prohibited. */
void calculate_value(uint16_t, uint32_t); 

void calculate_value(uint16_t x, uint32_t y) {
    /* ... */
}

/* --- MISRA COMPLIANT --- */
/* Compliant: Parameter names are explicitly provided in the prototype. 
   This matches the definition and clarifies the purpose of each parameter. */
void update_system_status(uint16_t status_id, uint32_t timestamp);

void update_system_status(uint16_t status_id, uint32_t timestamp) {
    /* Implementation uses the named parameters clearly */
    if (status_id > 0U) {
        /* Use timestamp */
    }
}