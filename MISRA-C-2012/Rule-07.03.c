#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 7.3
 * Rule: The lowercase character “l” shall not be used in a literal suffix.
 */

/* --- NON-COMPLIANT --- */
void lowercase_suffix_bad(void) {
    /* Violation: Using 'l' as a suffix is hard to read and easily confused with '1' */
    long val1 = 100l;
    
    /* Violation: Especially dangerous when combined with numbers */
    long long val2 = 123456l; 
}

/* --- MISRA COMPLIANT --- */
void uppercase_suffix_good(void) {
    /* Compliant: Using 'L' for long constants improves readability */
    long val1 = 100L;
    
    /* Compliant: Using 'LL' for long long constants */
    long long val2 = 123456LL;
    
    /* Compliant: Combining 'U' and 'L' is also standard practice for unsigned long */
    unsigned long val3 = 1000UL;
}