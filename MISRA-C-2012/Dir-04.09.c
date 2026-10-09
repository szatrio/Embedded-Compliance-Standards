#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.9
 * Directive: A function should be used in preference to a function-like macro
 *            where they are interchangeable.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: Function-like macro used for a simple arithmetic comparison */
#define MAX_BAD(a, b) (((a) > (b)) ? (a) : (b))

/* Non-compliant: Function-like macro used for square calculation */
#define SQUARE_BAD(x) ((x) * (x))

void process_macro_bad(void)
{
    uint32_t val = 5U;

    /* Dangerous: 'val' is incremented twice due to double evaluation in macro expansion */
    uint32_t result_max = MAX_BAD(val++, 10U);

    /* Dangerous: 'val' is evaluated twice here as well */
    uint32_t result_sq = SQUARE_BAD(val++);

    (void)result_max;
    (void)result_sq;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Static inline functions provide type safety, debuggability, and avoid double evaluation */
static inline uint32_t max_good(uint32_t a, uint32_t b)
{
    return (a > b) ? a : b;
}

static inline uint32_t square_good(uint32_t x)
{
    return x * x;
}

void process_function_good(void)
{
    uint32_t val = 5U;

    /* Compliant: 'val' is passed by value and evaluated exactly once */
    uint32_t result_max = max_good(val, 10U);
    val++;

    /* Compliant: Safe evaluation with explicit type checking */
    uint32_t result_sq = square_good(val);
    val++;

    (void)result_max;
    (void)result_sq;
}
