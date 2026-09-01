#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.12
 * Rule: A macro parameter used as an operand to the # or ## operators, which is
 *       itself subject to further macro replacement, shall only be used as an
 *       operand to these operators.
 */

#define MAX_BUFFER_SIZE  1024U

/* --- NON-COMPLIANT --- */

/* Violation: Parameter 'x' is used with # operator (#x) where it is NOT expanded,
   and also used as a plain variable (x) where it IS expanded in the same macro. */
#define PRINT_BUFFER_INFO_BAD(x) printf("Buffer Name: %s, Size: %u\n", #x, (x))

void test_rule_20_12_bad(void)
{
    /* Violation: MAX_BUFFER_SIZE is a macro passed to PRINT_BUFFER_INFO_BAD */
    /* PRINT_BUFFER_INFO_BAD(MAX_BUFFER_SIZE); */
}


/* --- MISRA COMPLIANT --- */

/* Compliant: Separate function to handle display logic without macro parameter ambiguity */
static inline void print_buffer_info(const char *name, uint32_t size)
{
    /* Implementation logic here */
    (void)name;
    (void)size;
}

/* Compliant: Macro parameter is strictly used ONLY with the stringification operator (#) */
#define GET_MACRO_NAME(x) #x

void test_rule_20_12_good(void)
{
    /* Compliant: Pass name (#) and value explicitly to avoid mixed expansion behavior */
    print_buffer_info(GET_MACRO_NAME(MAX_BUFFER_SIZE), MAX_BUFFER_SIZE);
}