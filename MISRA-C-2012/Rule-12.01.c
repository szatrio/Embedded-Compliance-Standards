#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 12.1
 * Rule: The precedence of operators within expressions should be explicit 
 * through the use of parentheses to prevent priority ambiguity.
 */
void test_compliance_12_1(void) {
    
    uint16_t status_register = 0x00FFU;
    uint16_t mask = 0x000FU;
    bool system_ready = false;

    /* --- NON-COMPLIANT --- */
    /* if (status_register & mask == 0x0005U) { system_ready = true; } */


    /* --- MISRA COMPLIANT --- */
    if ((status_register & mask) == 0x0005U) {
        system_ready = true;
    }
}
