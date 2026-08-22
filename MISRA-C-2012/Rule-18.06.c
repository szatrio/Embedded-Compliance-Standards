#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 18.6
 * Rule: The address of an object with automatic storage shall not be copied to another
 *       object that persists after the first object has ceased to exist.
 */

static uint32_t *g_ptr = NULL;

/* Non-compliant example 1: Returning address of automatic local variable */
uint32_t *func_bad_return(void)
{
    uint32_t local_var = 100U;

    /* Non-compliant: &local_var becomes indeterminate when function returns */
    return &local_var;
}

/* Non-compliant example 2: Storing local variable address to global pointer */
void func_bad_global(void)
{
    uint32_t local_var = 50U;

    /* Non-compliant: g_ptr persists after local_var ceases to exist */
    g_ptr = &local_var;
}

/* Compliant example 1: Returning pointer passed from caller */
uint32_t *func_good_param(uint32_t *p_param)
{
    if (p_param != NULL)
    {
        *p_param = 100U;
    }

    /* Compliant: Lifetime of p_param is managed by the caller */
    return p_param;
}

/* Compliant example 2: Assigning address of static/global variable */
static uint32_t g_var = 0U;

void func_good_global(void)
{
    /* Compliant: g_var has static storage duration and persists as long as g_ptr */
    g_ptr = &g_var;
}