#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.4
 * Rule: A macro shall not be defined with the same name as a keyword.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: Redefining the 'int' keyword */
#define int some_other_type

/* Non-compliant: Redefining the 'while' keyword */
#define while(E) for ( ; (E) ; )


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Defining a macro that expands to statements without keyword collision */
#define UNLESS(E) if ( ! (E) )

/* Compliant: Function-like macro using standard keywords within its body */
#define SEQ(S1, S2) do { \
    S1;                  \
    S2;                  \
} while ( false )

void test_rule_20_4_demo(void)
{
    uint8_t a = 5U;

    UNLESS (a == 0U)
    {
        /* Code execution */
    }
}