#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 10.7
 * Rule: If a composite expression is used as one operand of an operator 
 * in which the usual arithmetic conversions are performed then the other 
 * operand shall not have wider essential type.
 */

/* --- NON-COMPLIANT --- */
void test_non_compliant(uint16_t u16_a, uint16_t u16_b, uint32_t u32_c)
{
    /* Violation: The composite expression (u16_a + u16_b) is evaluated as uint16_t 
       and then combined with 'u32_c' which has a wider essential type. 
       Potential overflow occurs in (u16_a + u16_b) before adding u32_c. */
    uint32_t result = (u16_a + u16_b) + u32_c;
}

/* --- MISRA COMPLIANT --- */
void test_compliant(uint16_t u16_a, uint16_t u16_b, uint32_t u32_c)
{
    /* Compliant: Explicitly cast one operand of the composite expression to uint32_t 
       so both operands share the same wider essential type category. */
    uint32_t result = ((uint32_t)u16_a + u16_b) + u32_c;
}