#include <stdio.h>

/**
 * Compliance Check: MISRA C:2012 Rule 22.4
 * Rule: There shall be no attempt to write to a stream which has been opened as read-only.
 */

void file_io_example(void) {
    /* "r" mode means open for reading only */
    FILE *fp = fopen("config.txt", "r");

    if (fp != NULL) {
        /* --- NON-COMPLIANT --- */
        /* Violation: Attempting to write to a stream opened in 'r' mode. */
        (void)fputc('A', fp); 

        /* --- MISRA COMPLIANT --- */
        /* To write, the file must be opened in "w" (write) or "a" (append) mode. */
        
        (void)fclose(fp);
    }
}