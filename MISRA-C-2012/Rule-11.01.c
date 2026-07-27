#include <stdint.h>
#include <stddef.h> /* For NULL definition */

/**
 * Compliance Check: MISRA C:2012 Rule 11.1
 * Rule: Conversions shall not be performed between a pointer to a function and any other type.
 */

/* Define function pointer types with specific signatures */
typedef void (*fp_uint16_t)(uint16_t a);
typedef void (*fp_uint32_t)(uint32_t a);

/* Target function matching fp_uint16_t signature */
static void print_value(uint16_t a)
{
    (void)a; /* Prevent unused parameter compiler warning */
}

void rule_11_1_demo(void)
{
    /* ========================================================
     * NON-COMPLIANT EXAMPLES (VIOLATION)
     * ======================================================== */
    
    /* Violation: Casting function pointer to an incompatible function pointer type */
    fp_uint32_t ptr_invalid = (fp_uint32_t)print_value;

    /* Violation: Casting function pointer to a void pointer or object pointer */
    void *ptr_void = (void *)print_value;

    /* Violation: Casting function pointer to an integer scalar type */
    uint32_t func_addr = (uint32_t)print_value;


    /* ========================================================
     * MISRA COMPLIANT EXAMPLES
     * ======================================================== */

    /* Compliant: Assigning function name to a compatible function pointer type */
    fp_uint16_t ptr_valid = print_value;

    /* Compliant: Assigning NULL constant to a function pointer (Exception 1) */
    fp_uint16_t ptr_null = NULL;

    if (ptr_valid != NULL)
    {
        ptr_valid(10U);
    }

    /* Compliant: Casting function pointer to void to discard value/expression (Exception 2) */
    (void)ptr_null;
}