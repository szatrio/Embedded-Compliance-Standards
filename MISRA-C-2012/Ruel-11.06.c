#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 11.6
 * Rule: A cast shall not be performed between pointer to void and an arithmetic type
 */

void test_rule_11_6(void)
{
    void *ptr = NULL;
    uint32_t addr = 0x20000000U;
    float32_t val = 3.14f;

    /* --- NON-COMPLIANT --- */

    /* Violation: Casting void* directly to an integer type */
    addr = (uint32_t)ptr;

    /* Violation: Casting an integer directly to void* */
    ptr = (void *)addr;

    /* Violation: Casting floating-point to/from void* (Undefined Behavior) */
    ptr = (void *)val;


    /* --- MISRA COMPLIANT --- */

    /* Compliant: Exception 1 - Null pointer constant (0) cast to void* */
    ptr = (void *)0;

    /* Compliant: Proper way to pass address to void* (Use appropriate object pointer first) */
    uint32_t data = 100U;
    uint32_t *p_data = &data;
    ptr = (void *)p_data; /* Implicit/explicit conversion from object pointer to void* is allowed */
}