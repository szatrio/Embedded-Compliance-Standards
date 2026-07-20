#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 8.14
 * Rule: The restrict type qualifier shall not be used.
 */

/* --- NON-COMPLIANT --- */

/* Violation: Use of 'restrict' pointer qualifier is prohibited.
   It assumes non-overlapping memory regions, which can lead to undefined behavior 
   if the caller passes overlapping pointers. */
void copy_buffer_bad(uint8_t * restrict p_dest, const uint8_t * restrict p_src, uint32_t len) { /* Violation: 'restrict' used */
    uint32_t i;
    for (i = 0U; i < len; i++) {
        p_dest[i] = p_src[i];
    }
}

/* --- MISRA COMPLIANT --- */

/* Compliant: Pointers declared without 'restrict'.
   Safety and correct handling of potential memory overlap must be ensured explicitly if required. */
void copy_buffer_good(uint8_t *p_dest, const uint8_t *p_src, uint32_t len) { /* Compliant: No 'restrict' qualifier */
    uint32_t i;
    for (i = 0U; i < len; i++) {
        p_dest[i] = p_src[i];
    }
}