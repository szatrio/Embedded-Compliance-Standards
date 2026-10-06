#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.3
 * Directive: Assembly language shall be encapsulated and isolated.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Inline assembly is mixed directly inside application/business logic */
uint32_t calculate_and_store_bad(uint32_t val)
{
    uint32_t result = val * 2U;

    /* Non-compliant: Assembly language is embedded directly within C application code */
    __asm volatile ("NOP");

    return result;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/**
 * @brief  Isolated wrapper function for assembly instruction.
 * @note   Compliant with Dir 4.3: Assembly code is encapsulated into its own dedicated function.
 */
static inline void asm_nop(void)
{
    __asm volatile ("NOP");
}

/* Compliant: High-level application logic calls the encapsulated wrapper function */
uint32_t calculate_and_store_good(uint32_t val)
{
    uint32_t result = val * 2U;

    /* Compliant: Assembly is isolated; application code uses C function call interface */
    asm_nop();

    return result;
}