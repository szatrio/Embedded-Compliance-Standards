#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.2
 * Rule: The ', " or \ characters and the /* or // character sequences
 *       shall not occur in a header file name.
 */

/* Non-compliant examples */
#include "fi'le.h"            /* Non-compliant: contains single quote ' */
#include "sub\file.h"         /* Non-compliant: contains backslash \ */
#include "file/*comment*/.h"  /* Non-compliant: contains /* sequence */

/* Compliant examples */
#include "file.h"             /* Compliant: standard header name */
#include "./include/cpu.h"    /* Compliant: standard forward slash / for directory path */