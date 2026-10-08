#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.8
 * Directive: If a pointer to a structure or union is never dereferenced within
 *            a translation unit, then the implementation of the object should be hidden.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

/* Non-compliant: Struct layout is fully exposed in header, even though application code only passes pointers */
struct DisplayBufferBad
{
    uint8_t data[256];
    uint16_t length;
};

void init_display_bad(struct DisplayBufferBad *p_buf);


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Opaque pointer pattern. Struct layout is hidden in the .c implementation file */
typedef struct DisplayBufferGood DisplayBufferGood_t;

/* Function handles handle/pointer without needing to know internal struct layout */
void init_display_good(DisplayBufferGood_t *p_buf);