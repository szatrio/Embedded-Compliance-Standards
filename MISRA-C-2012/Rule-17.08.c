#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 17.8
 * Rule: A function parameter should not be modified.
 */

extern int16_t glob;

/* --- NON-COMPLIANT EXAMPLES --- */

void proc_bad(int16_t para)
{
    para = glob; /* Non-compliant: modifying scalar function parameter */
}

void ptr_bad(char *p, char *q)
{
    p = q;    /* Non-compliant: modifying the pointer parameter itself */
    *p = *q;  /* Compliant in itself, but operating on modified parameter p */
}


/* --- MISRA COMPLIANT EXAMPLES --- */

void proc_good(int16_t para)
{
    /* Compliant: Copy parameter to a local automatic object and modify the copy */
    int16_t local_para = para;
    local_para = glob;

    (void)local_para;
}

void ptr_good(char *p, const char *q)
{
    if ((p != NULL) && (q != NULL))
    {
        *p = *q; /* Compliant: Modifying the memory pointed to by p, NOT p itself */
    }
}