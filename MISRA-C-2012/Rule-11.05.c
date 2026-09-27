#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 11.5
 * Rule: A conversion should not be performed from pointer to void
 *       into pointer to object.
 */

/* Helper function returning a void pointer (e.g., custom buffer interface) */
extern void *get_buffer_address(void);

/* --- NON-COMPLIANT EXAMPLE --- */

void process_buffer_bad(void)
{
    void *v_ptr = get_buffer_address();

    /* Non-compliant: Conversion from 'void *' to 'uint32_t *' */
    uint32_t *u32_ptr = (uint32_t *)v_ptr;

    if (u32_ptr != NULL)
    {
        *u32_ptr = 0x12345678U;
    }
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant Example 1: Avoid void pointers in API design, use concrete type pointers */
extern uint32_t *get_typed_buffer_address(void);

void process_buffer_good(void)
{
    /* Compliant: Direct assignment using matching pointer types */
    uint32_t *u32_ptr = get_typed_buffer_address();

    if (u32_ptr != NULL)
    {
        *u32_ptr = 0x12345678U;
    }
}

/* Compliant Example 2: Copy bytes via memcpy/byte arrays when handling raw memory buffers */
void process_raw_bytes_good(const uint8_t *p_src, size_t len)
{
    uint32_t data_val = 0U;

    if ((p_src != NULL) && (len >= sizeof(uint32_t)))
    {
        /* Compliant: Safe byte-wise access or copying instead of void* casting */
        data_val = ((uint32_t)p_src[0])        |
                   ((uint32_t)p_src[1] << 8U)  |
                   ((uint32_t)p_src[2] << 16U) |
                   ((uint32_t)p_src[3] << 24U);
    }
    
    (void)data_val;
}