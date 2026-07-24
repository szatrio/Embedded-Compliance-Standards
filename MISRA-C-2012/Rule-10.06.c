#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 10.6
 * Rule: The value of a composite expression shall not be assigned to 
 * an object with wider essential type.
 */

/* --- NON-COMPLIANT --- */
void composite_bad(uint16_t u16_a, uint16_t u16_b)
{
    /* Violation: The composite expression (u16_a + u16_b) is evaluated in 16-bit 
       and can overflow before being assigned to wider 32-bit object. */
    uint32_t u32_res = u16_a + u16_b; 
}

/* --- MISRA COMPLIANT --- */
void composite_good(uint16_t u16_a, uint16_t u16_b)
{
    /* Compliant: Explicitly cast one operand to uint32_t before addition 
       to ensure the composite expression is evaluated using wider type. */
    uint32_t u32_res = (uint32_t)u16_a + u16_b;
}