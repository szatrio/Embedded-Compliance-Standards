#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.1
 * Directive: Run-time failures shall be minimized.
 */

#define ARRAY_SIZE 5U

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: Potential division by zero, null pointer dereference, and array out-of-bounds */
uint32_t process_data_bad(const uint32_t *p_array, uint32_t index, uint32_t divisor)
{
    /* Non-compliant: Dereferencing pointer without NULL check */
    /* Non-compliant: Unchecked array index access (can cause out-of-bounds read) */
    uint32_t value = p_array[index];

    /* Non-compliant: Division performed without checking if divisor is zero */
    return value / divisor;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: All potential run-time failure conditions are checked before execution */
bool process_data_good(const uint32_t *p_array, uint32_t index, uint32_t divisor, uint32_t *p_result)
{
    bool status = false;

    /* Compliant: Guard against NULL pointers, out-of-bounds access, and division by zero */
    if ((p_array != NULL) && (p_result != NULL) && (index < ARRAY_SIZE) && (divisor > 0U))
    {
        *p_result = p_array[index] / divisor;
        status = true;
    }

    return status;
}