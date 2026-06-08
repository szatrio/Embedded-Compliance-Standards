#include <stdint.h>
#include <stddef.h>
#include <stdlib.h> /* The use of malloc/free from this library is restricted by Rule 21.3 */

/**
 * Compliance Check: MISRA C:2012 Rule 21.3
 * Rule: The memory allocation and deallocation functions of <stdlib.h> shall not be used.
 */

/* Fixed-size buffer to replace dynamic memory */
#define MAX_BUFFER_SIZE 10U

/* --- NON-COMPLIANT --- */
/* Using dynamic memory allocation via malloc/free violates Rule 21.3. */
void process_data_bad(void) {
    /* Violation: 'malloc' is a dynamic memory allocation function from <stdlib.h> */
    uint16_t *ptr = (uint16_t *)malloc(sizeof(uint16_t) * MAX_BUFFER_SIZE);
    
    if (ptr != NULL) {
        ptr[0] = 100U;
        free(ptr); /* Violation: 'free' is also prohibited */
    }
}

/* --- MISRA COMPLIANT --- */
/* Static allocation ensures memory is determined at compile-time, 
   removing heap-related risks like fragmentation or allocation failures. */
void process_data_good(void) {
    /* Compliant: Static buffer is allocated in the data segment, 
       not the heap, and does not require <stdlib.h> functions. */
    static uint16_t static_buffer[MAX_BUFFER_SIZE];
    
    static_buffer[0] = 100U;
}