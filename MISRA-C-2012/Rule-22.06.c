#include <stdio.h>

/**
 * Compliance Check: MISRA C:2012 Rule 22.6
 * Rule: The value of a pointer to a FILE shall not be used 
 * after the associated stream has been closed.
 */

/* --- NON-COMPLIANT --- */
/* Using the FILE pointer after it has been closed. */
void use_after_close_bad(void) {
    FILE *fp = fopen("data.txt", "w");

    if (fp != NULL) {
        (void)fclose(fp);

        /* Violation: 'fp' is no longer valid, but we try to use it anyway. */
        (void)fputc('B', fp); 
    }
}

/* --- MISRA COMPLIANT --- */
/* Set pointer to NULL after closing to prevent accidental usage. */
void use_after_close_good(void) {
    FILE *fp = fopen("data.txt", "w");

    if (fp != NULL) {
        (void)fclose(fp);
        
        /* Compliant: Resetting pointer prevents accidental reuse. */
        fp = NULL; 
    }
}