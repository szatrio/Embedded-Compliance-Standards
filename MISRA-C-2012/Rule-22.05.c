#include <stdio.h>

/**
 * Compliance Check: MISRA C:2012 Rule 22.5
 * Rule: A pointer to a FILE object shall not be dereferenced.
 */

/* --- NON-COMPLIANT --- */
/* Accessing internal members of the FILE structure directly. */
void access_file_internal_bad(void) {
    FILE *fp = fopen("data.txt", "r");

    if (fp != NULL) {
        /* Violation: Dereferencing 'fp' to access internal structures.
           This is non-portable and unsafe. */
        // uint8_t flag = (*fp)._flags; 
        
        (void)fclose(fp);
    }
}

/* --- MISRA COMPLIANT --- */
/* Treat the FILE pointer as an opaque handle. */
void access_file_internal_good(void) {
    FILE *fp = fopen("data.txt", "r");

    if (fp != NULL) {
        /* Compliant: Passing the pointer to a standard library function 
           is the only way to interact with the stream. */
        int c = fgetc(fp); 
        
        (void)fclose(fp);
    }
}