#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.13
 * Rule: A pointer should point to a const-qualified type whenever possible.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Parameter 'p_data' does not modify the pointed object,
   so it should be declared as pointer to const (const uint32_t *p_data) */
uint32_t calculate_sum_bad(uint32_t *p_data, size_t length)
{
    uint32_t sum = 0U;

    if (p_data != NULL)
    {
        size_t i;
        for (i = 0U; i < length; i++)
        {
            sum += p_data[i]; /* Only reading, never modifying *p_data */
        }
    }

    return sum;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: 'p_data' is read-only, so it points to a const-qualified type */
uint32_t calculate_sum_good(const uint32_t *p_data, size_t length)
{
    uint32_t sum = 0U;

    if (p_data != NULL)
    {
        size_t i;
        for (i = 0U; i < length; i++)
        {
            sum += p_data[i];
        }
    }

    return sum;
}

/* Compliant: 'p_dest' is NOT const because the memory it points to IS modified */
void clear_buffer_good(uint8_t *p_dest, size_t length)
{
    if (p_dest != NULL)
    {
        size_t i;
        for (i = 0U; i < length; i++)
        {
            p_dest[i] = 0U; /* Modifying memory, so non-const pointer is appropriate */
        }
    }
}