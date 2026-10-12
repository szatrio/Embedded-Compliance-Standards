#include <stdint.h>
#include <stdlib.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.12
 * Directive: Dynamic memory allocation shall not be used.
 */

#define BUFFER_SIZE 64U

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Using malloc/free leads to heap fragmentation, memory leaks, and non-deterministic timing */
uint8_t *allocate_buffer_bad(void)
{
    /* Non-compliant: Dynamic memory allocation via standard library heap function */
    uint8_t *p_buf = (uint8_t *)malloc(BUFFER_SIZE * sizeof(uint8_t));
    
    return p_buf;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/**
 * @brief  Provides a statically allocated buffer.
 * @note   Compliant with Dir 4.12: Static memory allocation guarantees deterministic behavior and prevents heap exhaustion.
 */
static uint8_t s_static_buffer[BUFFER_SIZE];

uint8_t *get_buffer_good(void)
{
    /* Compliant: Returning pointer to a statically allocated memory pool with deterministic lifetime */
    return s_static_buffer;
}