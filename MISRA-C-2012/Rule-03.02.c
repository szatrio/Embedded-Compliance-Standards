#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 3.2
 * Rule: Line-splicing shall not be used in // comments.
 */

/* --- NON-COMPLIANT --- */
void line_splicing_bad(void) {
    uint16_t x = 10U;

    // This is a comment that uses line-splicing \
    x = 20U; /* This line is now part of the comment and is IGNORED! */

    /* Result: x remains 10, not 20. This causes a silent logic bug. */
}

/* --- MISRA COMPLIANT --- */
void line_splicing_good(void) {
    uint16_t x = 10U;

    // This is a comment that does not use line-splicing.
    x = 20U; /* This line is executed normally. */
}