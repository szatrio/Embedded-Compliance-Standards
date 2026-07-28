#include <stdint.h>

/* --- Forward Declaration (Incomplete Type) --- */
/* The structure is declared, but its members are not yet defined. 
 * Therefore, 'struct Configuration' is an incomplete type here. */
struct Configuration;

/* Function prototypes */
void process_config(struct Configuration *p_config);

/**
 * Compliance Check: MISRA C:2012 Rule 11.2
 * Rule: Conversions shall not be performed between a pointer to an 
 * incomplete type and any other type.
 */
void test_rule_11_2(void) 
{
    struct Configuration *p_cfg = (struct Configuration *)0;
    uint32_t *p_u32;
    uint32_t address = 0x20000000U;

    /* --- NON-COMPLIANT --- */
    /* Violation: Converting a pointer to an incomplete type ('struct Configuration *') 
     * directly into an integer or an unrelated object pointer type. */
    p_u32 = (uint32_t *)p_cfg;          /* Violation: Cast from incomplete type pointer */
    
    /* Violation: Converting an arithmetic type/integer into a pointer to an incomplete type */
    p_cfg = (struct Configuration *)address; /* Violation: Cast to incomplete type pointer */


    /* --- MISRA COMPLIANT --- */
    /* Compliant: Do not cast pointers of incomplete types. 
     * Access or manipulate incomplete types only through proper abstraction functions 
     * where the structure definition is fully visible (complete). */
    
    // Example usage of a valid function pointer call taking the incomplete type pointer
    if (p_cfg != (struct Configuration *)0) {
        process_config(p_cfg); /* Compliant: Passing the pointer without illegal casting */
    }
}