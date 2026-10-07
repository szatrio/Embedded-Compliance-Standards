#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.6
 * Directive: typedefs that indicate size and signedness should be used in place
 *            of the basic numerical types.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: Using basic numerical types directly without explicit size/signedness */
void process_data_bad(void)
{
    /* Non-compliant: 'int', 'short', and 'unsigned long' have compiler-dependent sizes */
    int count = 0;
    short speed = 100;
    unsigned long mask = 0xFFFFFFFFUL;

    (void)count;
    (void)speed;
    (void)mask;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Using C99 <stdint.h> typedefs that clearly define size and signedness */
void process_data_good(void)
{
    /* Compliant: Sizes and signedness are explicit and portable across targets */
    int32_t count = 0;
    int16_t speed = 100;
    uint32_t mask = 0xFFFFFFFFU;

    (void)count;
    (void)speed;
    (void)mask;
}

/* Exception: Basic types are allowed when defining a specific-length typedef itself, */
/* or for 'int' in 'main(int argc, char *argv[])' function signature. */
typedef signed int SINT_16; /* Compliant: Basic type used within typedef definition */