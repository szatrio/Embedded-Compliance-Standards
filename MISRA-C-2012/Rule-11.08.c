#include <stdint.h>

/* --- NON-COMPLIANT EXAMPLES --- */

void process_data(const uint8_t *c_ptr, volatile uint32_t *v_ptr)
{
    /* Violation: Casting away 'const' qualifier */
    uint8_t *p_data = (uint8_t *)c_ptr; 
    *p_data = 0x00U; /* Danger: Modifying read-only memory */

    /* Violation: Casting away 'volatile' qualifier */
    uint32_t *p_reg = (uint32_t *)v_ptr; 
    *p_reg = 0x12345678U; /* Danger: Bypassing volatile memory access */
}

/* --- MISRA COMPLIANT EXAMPLES --- */

void compliant_process_data(const uint8_t *c_ptr, volatile uint32_t *v_ptr)
{
    /* Compliant: Preserving 'const' qualifier */
    const uint8_t *p_const_data = c_ptr;
    uint8_t value = *p_const_data; /* Read-only operation permitted */
    (void)value;

    /* Compliant: Preserving 'volatile' qualifier */
    volatile uint32_t *p_volatile_reg = v_ptr;
    *p_volatile_reg = 0x12345678U; /* Proper hardware register access */
}