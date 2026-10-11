#include <stdint.h>
#include <string.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.11
 * Directive: The validity of values passed to library functions shall be checked.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Passing unchecked pointers and lengths directly to standard library memcpy */
void copy_buffer_bad(const char *p_src, char *p_dest, size_t count)
{
    /* Non-compliant: Standard library function called without parameter verification (e.g., NULL or zero length) */
    (void)memcpy(p_dest, p_src, count);
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/**
 * @brief  Safely copies buffer contents using standard library functions.
 * @note   Compliant with Dir 4.11: Validating all arguments before calling library functions.
 */
void copy_buffer_good(const char *p_src, char *p_dest, size_t count, size_t max_dest_size)
{
    /* Compliant: Ensure non-null pointers, non-zero count, and bounds compliance prior to library call */
    if ((p_src != NULL) && (p_dest != NULL) && (count > 0U) && (count <= max_dest_size))
    {
        (void)memcpy(p_dest, p_src, count);
    }
    else
    {
        /* Handle invalid parameter error or safety fallback */
    }
}