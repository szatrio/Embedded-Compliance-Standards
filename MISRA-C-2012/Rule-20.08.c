#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.8
 * Rule: The controlling expression of a #if or #elif preprocessing directive
 *       shall evaluate to 0 or 1.
 */

#define FALSE 0
#define TRUE  1
#define VAL_A 10
#define VAL_B 20

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: Controlling expression evaluates to 10 (not 0 or 1) */
#if 10[cite: 1]
    /* Excluded or included code */
#endif

/* Non-compliant: Numeric evaluation results in a value other than 0 or 1 */
#if VAL_A
    /* Excluded or included code */
#endif


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Expression evaluates directly to 0 */
#if FALSE[cite: 1]
    /* Excluded code */
#endif

/* Compliant: Expression evaluates directly to 1 */
#if TRUE
    /* Included code */
#endif

/* Compliant: Macro existence check using defined() evaluates to 0 or 1 */
#if !defined(X)[cite: 1]
    /* Code execution */
#endif

/* Compliant: Relational comparison evaluates to 0 or 1 */
#if VAL_A < VAL_B[cite: 1]
    /* Code execution */
#endif