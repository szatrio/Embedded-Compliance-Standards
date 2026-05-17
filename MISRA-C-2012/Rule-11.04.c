#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 11.4
 * Rule: Avoid conversion between pointers and integers, 
 * except for explicit memory-mapped peripheral register access.
 */
void test_compliance_11_4(void) {
    
    /* Variable stored in RAM */
    int32_t standard_variable = 42;
    
    /* Destination pointer */
    int32_t *memory_ptr = &standard_variable;

    /* --- NON-COMPLIANT --- */
    /* Converting a random integer arithmetic directly into a pointer.
       This is highly dangerous as it points to an unpredictable RAM address. */
    // uint32_t dangerous_address = 0x20001000U;
    // memory_ptr = (int32_t *)dangerous_address; 


    /* --- MISRA COMPLIANT (The Allowed Exception) --- */
    /* Mapping a specific Hardware Register Address (e.g., STM32 GPIO Register).
       This integer-to-pointer conversion is allowed because it targets 
       a fixed, documented peripheral zone, not general RAM. */
    volatile uint32_t *gpio_a_moder = (volatile uint32_t *)0x40020000U;

    /* Safely write to the hardware register */
    *gpio_a_moder = 0x00000001U; 
}
