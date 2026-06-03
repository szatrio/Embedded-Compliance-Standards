#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 17.2
 * Rule: Functions shall not call themselves, either directly or indirectly.
 */

/* --- NON-COMPLIANT --- */
/* Direct recursion: The function calls itself. This can lead to 
   uncontrolled stack growth. */
uint32_t factorial(uint32_t n) {
    if (n <= 1U) {
        return 1U;
    } else {
        return (n * factorial(n - 1U)); /* Recursion! */
    }
}

/* --- MISRA COMPLIANT --- */
/* Use iteration (loops) instead of recursion. This keeps stack usage 
   predictable and constant. */
uint32_t factorial_compliant(uint32_t n) {
    uint32_t result = 1U;
    uint32_t i;
    
    for (i = 1U; i <= n; i++) {
        result = result * i;
    }
    return result;
}
