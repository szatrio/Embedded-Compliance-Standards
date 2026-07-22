#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 9.3
 * Rule: Arrays shall not be partially initialized.
 */

/* --- NON-COMPLIANT --- */

void test_non_compliant(void) {
    /* Violation: Array of 5 elements only has 2 initializers.
       Remaining elements are implicitly zero-initialized by the compiler. */
    uint32_t arr1[5] = { 1U, 2U }; 

    /* Violation: 2D array partially initialized (second row is missing initializers). */
    uint16_t matrix[2][3] = {
        { 1U, 2U, 3U }
        /* Missing second row initializer */
    };
}

/* --- MISRA COMPLIANT --- */

void test_compliant(void) {
    /* Compliant: Option 1 - Fully initialize all elements explicitly. */
    uint32_t arr1[5] = { 1U, 2U, 3U, 4U, 5U }; 

    /* Compliant: Option 2 - Explicitly zero-initialize the entire array using { 0 }.
       (MISRA C allows { 0 } as a special compliant way to zero-fill all elements). */
    uint32_t arr2[5] = { 0U }; 

    /* Compliant: All elements of 2D array explicitly initialized. */
    uint16_t matrix[2][3] = {
        { 1U, 2U, 3U },
        { 4U, 5U, 6U }
    };
}