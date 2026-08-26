#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.3
 * Rule: The #include directive shall be followed by either a <filename> or "filename" sequence.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: Missing quotes or angle brackets */
/* #include file2.h */

#define FILENAME file2.h
/* Non-compliant: Macro expands to file2.h without "" or <> */
/* #include FILENAME */

#define BASE "base"
#define EXT  ".ext"
/* Non-compliant: Macro string concatenation does not form a valid sequence after preprocessing */
/* #include BASE EXT */


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Standard double quote header inclusion */
#include "filename.h"

/* Compliant: Standard angle bracket header inclusion */
#include <stddef.h>

/* Compliant: Valid macro expanding to a double-quoted string literal */
#define HEADER "filename.h"
#include HEADER

void test_rule_20_3_demo(void)
{
    /* Rule 20.3 checking done at preprocessor stage */
}