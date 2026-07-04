#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 5.8
 * Rule: Identifiers that define objects or functions with external linkage 
 * shall be unique.
 */

/* --- NON-COMPLIANT --- */
/* Violation: Both functions have external linkage and share the same name,
   which causes a symbol collision at the linker stage. */

void system_init(void) { /* Defined in module_a.c */ }
void system_init(void) { /* Defined in module_b.c */ }

/* --- MISRA COMPLIANT --- */
/* Compliant: Use 'static' for internal functions to avoid external linkage,
   and use unique prefixes for global (external) functions. */

/* Internal functions: Static linkage, safe to share names across files */
static void internal_setup_a(void) { /* ... */ }
static void internal_setup_b(void) { /* ... */ }

/* External functions: Unique names ensure no linker conflicts */
void module_a_init(void) {
    internal_setup_a();
}

void module_b_init(void) {
    internal_setup_b();
}