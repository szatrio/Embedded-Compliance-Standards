#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 12.2
 * Rule: The right hand operand of a shift operator shall lie in the range 
 * zero to one less than the width in bits of the essential type 
 * of the left hand operand.
 */

/* Function demonstrating Rule 12.2 violations and compliance */
void check_shift_operations(uint8_t shift_amount)
{
    uint16_t val16 = 0x00FFU; /* 16-bit unsigned integer (valid range: 0 to 15) */
    uint32_t val32 = 0x0000FFFFUL; /* 32-bit unsigned integer (valid range: 0 to 31) */
    
    uint16_t result16;
    uint32_t result32;

    /* --- NON-COMPLIANT --- */

    /* Violation: Shifting 16-bit variable by 16 bits (exceeds max index 15) */
    result16 = val16 << 16U;

    /* Violation: Shifting 32-bit variable by 32 bits (exceeds max index 31) */
    result32 = val32 >> 32U;

    /* Violation: Negative shift count is undefined behavior */
    result16 = val16 << -1;

    /* Violation: Shift amount is variable and might exceed bit width (0..15) at runtime */
    result16 = val16 << shift_amount;


    /* --- MISRA COMPLIANT --- */

    /* Compliant: Shift count is within valid range (0 to 15 for uint16_t) */
    result16 = val16 << 8U;

    /* Compliant: Shift count is within valid range (0 to 31 for uint32_t) */
    result32 = val32 >> 31U;

    /* Compliant: Bounds-checking dynamic shift count before shifting */
    if (shift_amount < 16U)
    {
        result16 = val16 << shift_amount;
    }
    else
    {
        /* Safe fallback logic if requested shift is out of bounds */
        result16 = 0U;
    }
}