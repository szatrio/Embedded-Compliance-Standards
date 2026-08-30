#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.9
 * Rule: All identifiers used in the controlling expression of #if or #elif
 *       preprocessing directives shall be #define'd before evaluation.
 */

/* Target definitions */
#define FEATURE_A_ENABLED  1
#define OPTION_LEVEL       2

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: FEATURE_B_ENABLED is not #define'd, preprocessor implicitly substitutes it with 0 */
#if FEATURE_B_ENABLED
    /* Code execution */
#endif

/* Non-compliant: UNDEFINED_MACRO is not #define'd before comparison */
#if UNDEFINED_MACRO == 1
    /* Code execution */
#endif


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: FEATURE_A_ENABLED was explicitly #define'd */
#if FEATURE_A_ENABLED == 1
    /* Code execution */
#endif

/* Compliant: OPTION_LEVEL was explicitly #define'd */
#if OPTION_LEVEL > 1
    /* Code execution */
#endif

/* Compliant: Operator defined() checks for existence, so identifier is not required to be #define'd */
#if defined(FEATURE_C_ENABLED)
    /* Code execution */
#endif