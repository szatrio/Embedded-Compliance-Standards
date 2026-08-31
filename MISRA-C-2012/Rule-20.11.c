#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.11
 * Rule: A macro parameter immediately following a # operator shall not
 *       immediately be followed by a ## operator.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: #x is immediately followed by ## operator */
#define CONCAT_STRING_BAD(x, y) #x ## y


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Using stringification operator (#) alone */
#define TO_STRING(x) #x

/* Compliant: Using token concatenation operator (##) alone */
#define CONCAT_TOKENS(x, y) x ## y

void test_rule_20_11_demo(void)
{
    /* Rule 20.11 checking is evaluated during the preprocessing phase */
    const char *str = TO_STRING(123);
    uint32_t CONCAT_TOKENS(var_, 1) = 100U;

    (void)str;
    (void)var_1;
}