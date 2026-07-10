#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 7.4
 * Rule: A string literal shall not be assigned to an object unless 
 * the object’s type is “pointer to const-qualified char”.
 */

/* --- NON-COMPLIANT --- */
void string_literal_bad(void) {
    /* Violation: Assigning a string literal to a non-const pointer.
       This is dangerous because it allows code to modify the string literal,
       which may reside in read-only memory. */
    char *ptr = "Error"; 

    /* Attempting to modify this string will cause undefined behavior */
    ptr[0] = 'X'; 
}

/* --- MISRA COMPLIANT --- */
void string_literal_good(void) {
    /* Compliant: Using 'const char *' ensures that the compiler prevents 
       accidental modification of the string literal. */
    const char *ptr = "Status OK";
    
    /* Good practice: Using an array if a modifiable string buffer is needed */
    char buffer[] = "Status OK";
    buffer[0] = 'X'; /* This is allowed because it is a local array, not a literal */
}