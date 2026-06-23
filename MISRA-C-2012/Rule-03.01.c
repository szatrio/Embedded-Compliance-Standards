#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 3.1
 * Rule: The character sequences /* and // shall not be used within a comment.
 */

/* --- MISRA COMPLIANT --- */
/* * This is a compliant comment.
 * Instead of nesting comments, use descriptive text to explain 
 * the logic without using comment delimiters.
 */
void rule_3_1_good(void) {
    /* Code here */
}