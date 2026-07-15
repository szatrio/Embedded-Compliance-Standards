#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.5
 * Rule: An external object or function shall be declared once 
 * in one and only one file.
 */

/* --- NON-COMPLIANT --- */
/* Violation: Declaring the same external function multiple times in the same scope 
   (or across multiple headers included in one file) is a violation of 8.5. */

extern void system_init(void); /* First declaration */
extern void system_init(void); /* Violation: Redundant declaration */

/* --- MISRA COMPLIANT --- */
/* Compliant: The function is declared only once. 
   In a real project, this would be in a single header file (e.g., system.h). */

extern void reset_device(void);

/* Definition (Implementation) */
void reset_device(void) {
    /* Implementation logic here */
}