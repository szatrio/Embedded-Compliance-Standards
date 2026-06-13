#include <stdint.h>
#include <stdlib.h>

/**
 * Compliance Check: MISRA C:2012 Rule 22.2
 * Rule: A block of memory shall only be freed if it was allocated 
 * by means of a Standard Library function (e.g., malloc, calloc, realloc).
 */

/* --- NON-COMPLIANT --- */
/* Attempting to free memory that was not allocated via dynamic allocation. */
void process_memory_bad(void) {
    uint16_t local_data = 100U;
    uint16_t *ptr = &local_data;

    /* Violation: 'ptr' points to stack memory. 
       Calling free() on stack memory is undefined behavior and 
       will likely cause a system crash. */
    free(ptr); 
}

/* --- MISRA COMPLIANT --- */
/* Ensure the pointer passed to free() is strictly sourced from 
   a Standard Library allocation function. */
void process_memory_good(void) {
    uint16_t *ptr = (uint16_t *)malloc(sizeof(uint16_t) * 1U);
    
    if (ptr != NULL) {
        *ptr = 100U;
        
        /* Compliant: 'ptr' was allocated by a Standard Library function,
           making it safe and compliant to free. */
        free(ptr);
        ptr = NULL; /* Good practice: prevent dangling pointer */
    }
}