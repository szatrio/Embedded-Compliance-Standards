#include <stdint.h>
#include <stdbool.h>
#include <float.h>

/**
 * Compliance Check: MISRA C:2012 Rule 21.12
 * Rule: The exception handling features of <fenv.h> should not be used.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

#if 0
#include <fenv.h>

float divide_bad(float numerator, float denominator)
{
    float result = 0.0f;

    /* Non-compliant: Using <fenv.h> exception handling features */
    feclearexcept(FE_ALL_EXCEPT);
    result = numerator / denominator;

    if (fetestexcept(FE_DIVBYZERO) != 0)
    {
        /* Handle division by zero via fenv exception flag */
        result = 0.0f;
    }

    return result;
}
#endif


/* --- MISRA COMPLIANT EXAMPLE --- */

/* Compliant: Perform range/domain checks BEFORE performing float operations */
bool divide_good(float numerator, float denominator, float *p_result)
{
    bool is_success = false;

    if (p_result != NULL)
    {
        /* Compliant: Prevent division by zero and extreme values explicitly */
        if ((denominator > FLT_EPSILON) || (denominator < -FLT_EPSILON))
        {
            *p_result = numerator / denominator;
            is_success = true;
        }
        else
        {
            *p_result = 0.0f; /* Safe fallback */
        }
    }

    return is_success;
}