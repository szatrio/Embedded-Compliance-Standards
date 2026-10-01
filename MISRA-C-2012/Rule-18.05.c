#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 18.5
 * Rule: Declarations should contain no more than two levels
 *       of pointer nesting.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: 3 levels of explicit pointer nesting */
typedef int8_t *** BadPtrType;

void pointer_nesting_bad(void)
{
    uint8_t ***p3; /* Non-compliant: 3 levels of pointer nesting */

    (void)p3;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: 1 level of pointer nesting */
typedef int8_t * Level1Ptr;

/* Compliant: 2 levels of pointer nesting */
typedef int8_t ** Level2Ptr;

void pointer_nesting_good(void)
{
    uint8_t *p1;   /* Compliant: 1 level */
    uint8_t **p2;  /* Compliant: 2 levels (maximum allowed) */

    (void)p1;
    (void)p2;
}

/* Compliant Alternative: Use a struct to encapsulate lower levels 
   if complex data structures are strictly required */
typedef struct {
    uint8_t *data;
} DataBuffer_t;

void struct_encapsulation_good(DataBuffer_t **ppBuffer)
{
    /* Compliant: ppBuffer has 2 levels of pointer nesting, 
       and access to inner data is structured safely via member selection */
    if ((ppBuffer != NULL) && (*ppBuffer != NULL))
    {
        uint8_t *pData = (*ppBuffer)->data;
        (void)pData;
    }
}