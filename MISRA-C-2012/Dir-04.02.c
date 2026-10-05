#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.2
 * Directive: All usage of assembly language should be documented.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Assembly language inserted without any explanatory documentation */
void disable_interrupts_bad(void)
{
    /* Non-compliant: Undocumented assembly instruction with no context or side-effect explanation */
    __asm volatile ("cpsid i");
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/**
 * @brief  Disables global interrupts on ARM Cortex-M processors.
 * @note   Assembly Usage Documentation (MISRA C:2012 Dir 4.2):
 *         - Instruction : CPSID I (Change Processor State - Disable Interrupts)
 *         - Target Arch : ARMv7-M / ARMv6-M (Cortex-M core)
 *         - Purpose     : Enter a critical section by masking PRIMASK register.
 *         - Side Effects: Prevents all configurable interrupts from triggering.
 *         - Inputs/Out  : None.
 */
void disable_interrupts_good(void)
{
    /* Compliant: Inline assembly is fully documented with clear purpose and target scope */
    __asm volatile ("cpsid i" : : : "memory");
}