#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.8
 * Rule: The static storage class specifier shall be used in all 
 * declarations of objects and functions that have internal linkage.
 */

/* --- NON-COMPLIANT --- */
/* Violation: Declaring or defining an internal object/function without 'static' 
   keyword, making it accidentally visible as external linkage if not restricted. */

uint16_t local_counter = 0U; /* Violation: Intended for local file use but missing 'static' */

void local_helper(void) {   /* Violation: Missing 'static' specifier */
    /* Local logic */
}


/* --- MISRA COMPLIANT --- */
/* Compliant: Explicitly using 'static' enforces internal linkage 
   and prevents namespace pollution or accidental external access. */

static uint16_t g_local_counter = 0U; /* Compliant: Explicit internal linkage */

static void compliant_helper(void);   /* Compliant: Declaration with static */

/* Definition */
static void compliant_helper(void) {
    /* Implementation logic here */
}