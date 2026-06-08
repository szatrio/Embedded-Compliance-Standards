#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 17.3
 * Rule: A function shall not be declared implicitly.
 */

/* --- NON-COMPLIANT --- */
/* Calling a function without a prior prototype forces the compiler 
   to make implicit assumptions about the function's signature. */
void process_data_bad(void) {
    uint16_t x = 10U;
    
    /* Violation: 'calculate_square' is not declared yet. 
       The compiler assumes int calculate_square() */
    uint16_t result = calculate_square(x); 
}

/* --- MISRA COMPLIANT --- */
/* The prototype provides the compiler with the function's signature
   before it is called, ensuring type safety and explicit declaration. */
static uint16_t calculate_square(uint16_t input_val);

void process_data_good(void) {
    uint16_t x = 10U;
    
    /* Compliant: Prototype is visible, so the call is explicit. */
    uint16_t result = calculate_square(x); 
}

/* Function definition */
static uint16_t calculate_square(uint16_t input_val) {
    return (uint16_t)(input_val * input_val);
}