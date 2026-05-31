#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 18.1
 * Rule: A pointer resulting from arithmetic on a pointer operand shall 
 * address an element of the same array or a location one past the end of the array.
 */
void test_compliance_18_1(void) {
    
    uint8_t buffer_alpha[5] = {10, 20, 30, 40, 50};
    uint8_t buffer_beta[5]  = {60, 70, 80, 90, 100};
    
    uint8_t *ptr = NULL;

    /* --- NON-COMPLIANT --- */
    /* Attempting to access memory by offsetting a pointer beyond its assigned 
       array boundaries. Even if the physics of RAM allows it (e.g., pointing into buffer_beta), 
       it triggers Undefined Behavior in C. */
    // ptr = &buffer_alpha[0];
    // ptr = ptr + 6; /* Out of bounds of buffer_alpha */


    /* --- MISRA COMPLIANT --- */
    /* Pointer arithmetic stays strictly within the boundaries of the intended array. 
       MISRA allows pointing to "one past the end" for loop terminations, but never accessing it. */
    ptr = &buffer_alpha[0];
    
    /* Safely increment within the 5-element boundary */
    ptr = ptr + 3; 
    *ptr = 35U;    /* Modifies buffer_alpha[3] safely */
}
