#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.7
 * Rule: Expressions resulting from the expansion of macro parameters 
 * shall be enclosed in parentheses to prevent operator precedence issues.
 */

/* --- NON-COMPLIANT --- */
/* Macro parameters and the overall expression are not enclosed in parentheses. 
   This can cause catastrophic expansion bugs depending on how the macro is called. */
/* #define BAD_MULTIPLICATION_MACRO(x, y)     x * y */


/* --- MISRA COMPLIANT --- */
/* Every single parameter operand AND the final expanded expression 
   must be strictly wrapped within individual parentheses. */
#define SAFE_MULTIPLICATION_MACRO(x, y)    ((x) * (y))

void test_compliance_20_07(void) {
    
    uint16_t math_result = 0U;

    /* --- NON-COMPLIANT EXPANSION --- */
    /* If called with BAD_MULTIPLICATION_MACRO(2 + 3, 4), the preprocessor 
       expands it literally to: 2 + 3 * 4. 
       Due to operator precedence, 3 * 4 is done first (12), then + 2 = 14 (WRONG). */


    /* --- MISRA COMPLIANT EXPANSION --- */
    /* Expands safely to: ((2 + 3) * (4)) -> (5 * 4) = 20 (CORRECT). */
    math_result = SAFE_MULTIPLICATION_MACRO(2U + 3U, 4U);
}
