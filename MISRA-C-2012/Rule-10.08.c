#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 10.8
 * Rule: The value of a composite expression shall not be cast to a 
 * different essential type category or a wider essential type.
 */

/* --- NON-COMPLIANT --- */
void test_non_compliant(uint16_t u16_a, uint16_t u16_b)
{
    /* Violation 1: Casting composite result to a wider type AFTER addition.
       Overflow occurs during (u16_a + u16_b) before casting takes effect. */
    uint32_t res_wide = (uint32_t)(u16_a + u16_b);

    /* Violation 2: Casting composite result to a different category (unsigned to signed). */
    int16_t res_signed = (int16_t)(u16_a + u16_b);
}

/* --- MISRA COMPLIANT --- */
void test_compliant(uint16_t u16_a, uint16_t u16_b)
{
    /* Compliant: Cast an operand BEFORE addition to widen the evaluation context. */
    uint32_t res_wide = (uint32_t)u16_a + u16_b;

    /* Compliant: Cast an operand BEFORE addition to change category prior to operation. */
    int32_t res_signed = (int32_t)u16_a + (int32_t)u16_b;
}