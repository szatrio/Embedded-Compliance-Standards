#include <stdint.h>
#include <string.h>

/**
 * Compliance Check: MISRA C:2012 Rule 19.1
 * Rule: An object shall not be assigned or copied to an overlapping object.
 */

/* --- NON-COMPLIANT --- */
/* Copying memory that overlaps. */
void copy_memory_bad(void) {
    uint8_t buffer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /* Violation: 'buffer' and '&buffer[2]' overlap.
       Using memcpy on overlapping memory is undefined behavior. */
    memcpy(&buffer[2], &buffer[0], 5U); 
}

/* --- MISRA COMPLIANT --- */
/* Use memmove() if memory regions are overlapping, or ensure no overlap. */
void copy_memory_good(void) {
    uint8_t buffer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /* Compliant: memmove() is specifically designed to handle 
       overlapping memory safely. */
    memmove(&buffer[2], &buffer[0], 5U);
}