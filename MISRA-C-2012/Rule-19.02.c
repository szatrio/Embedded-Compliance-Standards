#include <stdint.h>
#include <string.h>

/**
 * Compliance Check: MISRA C:2012 Rule 19.2
 * Rule: The union keyword should not be used.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Use of union keyword */
typedef union
{
    uint32_t ul;
    uint16_t us;
} DataConverter_t;

uint32_t zext_bad(uint16_t s)
{
    DataConverter_t tmp;

    tmp.us = s;
    
    /* Non-compliant: Writing 'us' and reading back 'ul' returns an unspecified value
       and relies on target endianness (MISRA C:2012 Rule 19.2 example) */
    return tmp.ul; /* cite: 1 */
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant Example 1: Use explicit bitwise operations instead of union for type conversions */
uint32_t zext_good(uint16_t s)
{
    /* Compliant: Explicit integer cast/promotion with predictable behavior */
    return (uint32_t)s;
}

/* Compliant Example 2: Use memcpy for safe byte-level inspection when type punning is unavoidable */
void inspect_bytes_good(uint32_t input_val, uint8_t dest_bytes[4])
{
    if (dest_bytes != NULL)
    {
        /* Compliant: Explicitly copying bytes avoids union access pitfalls */
        (void)memcpy(dest_bytes, &input_val, sizeof(input_val));
    }
}