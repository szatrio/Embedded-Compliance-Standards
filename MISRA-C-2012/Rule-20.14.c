#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.14
 * Rule: All #else, #elif and #endif preprocessor directives shall reside in
 *       the same file as the #if, #ifdef or #ifndef directive to which they are related.
 */

/* ========================================================================== */
/* NON-COMPLIANT EXAMPLE                                                      */
/* ========================================================================== */

/* --- bad_header.h --- */
/* 
#include "bad_header.h"
#else
    #define STATUS 0
#endif
*/

void test_rule_20_14_bad(void)
{
#ifdef OPTION_ENABLED
    /* Non-compliant: #if opened here, but #else / #endif are hidden inside bad_header.h */
    #include "bad_header.h"
}


/* ========================================================================== */
/* MISRA COMPLIANT EXAMPLE                                                    */
/* ========================================================================== */

/* --- good_header.h --- */
#ifndef GOOD_HEADER_H
#define GOOD_HEADER_H

/* Compliant: Whole conditional block (#ifndef ... #endif) is self-contained in this header */
#define CONFIG_VAL 100U

#endif /* GOOD_HEADER_H */


/* --- main.c --- */
#define SYSTEM_ACTIVE 1

void test_rule_20_14_good(void)
{
#if (SYSTEM_ACTIVE == 1)
    /* Compliant: #if, #else, and #endif all reside in this same source file */
    uint32_t mode = 1U;
#else
    uint32_t mode = 0U;
#endif

    (void)mode;
}