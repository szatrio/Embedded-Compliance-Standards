#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 14.4
 * Rule: The controlling expression of an if-statement or a iteration-statement 
 * shall have an essentially Boolean type to prevent implicit integer-to-boolean conversions.
 */
void test_compliance_14_4(void) {
    
    uint8_t fault_counter = 3U;
    bool is_system_active = true;
    uint8_t value = 0U;

    /* --- NON-COMPLIANT --- */
    /* Using an integer type as a boolean condition. 
       The compiler implicitly treats non-zero values as true. */
    /* if (fault_counter) { value = 1U; } */


    /* --- MISRA COMPLIANT --- */
    /* Controlling expressions must evaluate explicitly to a boolean type. */
    if (fault_counter > 0U) {
        value = 1U;
    }

    if (is_system_active) {
        value = 2U;
    }
}
