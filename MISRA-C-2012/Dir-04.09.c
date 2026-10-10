#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.9
 * Directive: A function should be used in preference to a function-like macro
 *            where they are interchangeable.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Function-like macro used for arithmetic comparison and square calculation */
#define MAX_BAD(a, b) (((a) > (b)) ? (a) : (b))
#define SQUARE_BAD(x) ((x) * (x))

void process_macro_bad(void)
{
    uint32_t val = 5U;

    /* Non-compliant: 'val' is incremented twice due to double evaluation in macro expansion */
    uint32_t result_max = MAX_BAD(val++, 10U);

    /* Non-compliant: 'val' is evaluated twice here as well, causing unexpected results */
    uint32_t result_sq = SQUARE_BAD(val++);

    (void)result_max;
    (void)result_sq;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/**
 * @brief  Computes the maximum of two values safely.
 * @note   Compliant with Dir 4.9: Using inline function instead of a function-like macro.
 */
static inline uint32_t max_good(uint32_t a, uint32_t b)
{
    return (a > b) ? a : b;
}

/**
 * @brief  Computes the square of a value safely.
 */
static inline uint32_t square_good(uint32_t x)
{
    return x * x;
}

void process_function_good(void)
{
    uint32_t val = 5U;

    /* Compliant: Arguments are passed by value and evaluated exactly once */
    uint32_t result_max = max_good(val, 10U);
    val++;

    /* Compliant: Safe evaluation with explicit type checking and no side-effect traps */
    uint32_t result_sq = square_good(val);
    val++;

    (void)result_max;
    (void)result_sq;
}