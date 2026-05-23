#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 13.2
 * Rule: The value of an expression and its common sub-expressions 
 * shall be the same under all allowed orders of evaluation.
 */
void test_compliance_13_2(void) {
    
    uint8_t index = 0U;
    uint8_t data_array[5] = {10, 20, 30, 40, 50};
    uint8_t value_one = 0U;
    uint8_t value_two = 0U;

    /* --- NON-COMPLIANT --- */
    /* Incrementing a variable and reading it within the same expression.
       The C standard does not guarantee whether the increment happens before or 
       after the second operand is evaluated, leading to compiler-dependent results. */
    // value_one = data_array[index] + data_array[++index];


    /* --- MISRA COMPLIANT --- */
    /* Separate the operation into distinct, sequential steps to guarantee 
       the exact evaluation order regardless of the compiler used. */
    value_two = data_array[index];
    index++;
    if (index < 5U) {
        value_two += data_array[index];
    }
}
