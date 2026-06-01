#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 10.1
 * Rule: Operands to a bitwise operator shall have an essentially unsigned type.
 */
void test_compliance_10_01(void) {
    
    int8_t signed_mask = -2;
    uint8_t unsigned_mask = 0xFEU;
    uint8_t register_value = 0xFFU;
    uint8_t result = 0U;

    /* --- NON-COMPLIANT --- */
    /* Performing bitwise operations on signed integers. 
       The representation of sign bits during shifts or bitwise inversions 
       is compiler-dependent and can lead to unexpected math logic. */
    // result = register_value & signed_mask;


    /* --- MISRA COMPLIANT --- */
    /* Bitwise operators must strictly use explicitly unsigned types. 
       This ensures that bit shifting and masking behave deterministically. */
    result = register_value & unsigned_mask;
}
