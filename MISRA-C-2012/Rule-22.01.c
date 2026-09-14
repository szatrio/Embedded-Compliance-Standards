#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Compliance Check: MISRA C:2012 Rule 22.1
 * Rule: All resources obtained dynamically by means of Standard Library
 *       functions shall be explicitly released.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

void resource_leak_bad(void)
{
    /* Non-compliant: Memory allocated via malloc is never released with free() */
    uint8_t *ptr = (uint8_t *)malloc(100U);[cite: 2]

    if (ptr != NULL)
    {
        *ptr = 0xAAU;
    }
    /* Function ends without calling free(ptr), causing a memory leak */[cite: 2]
}

void file_leak_bad(void)
{
    /* Non-compliant: File opened with fopen is never closed with fclose() */
    FILE *fp = fopen("config.bin", "rb");[cite: 2]

    if (fp != NULL)
    {
        /* Process file content */
    }
    /* Function ends without calling fclose(fp), causing a stream leak */[cite: 2]
}


/* --- MISRA COMPLIANT EXAMPLES --- */

void resource_management_good(void)
{
    /* Compliant: Memory is allocated and explicitly released */
    uint8_t *ptr = (uint8_t *)malloc(100U);[cite: 2]

    if (ptr != NULL)
    {
        *ptr = 0xAAU;

        /* Explicitly release memory resource */
        free(ptr);[cite: 2]
        ptr = NULL;
    }
}

void file_management_good(void)
{
    /* Compliant: File handle is opened and explicitly closed */
    FILE *fp = fopen("config.bin", "rb");[cite: 2]

    if (fp != NULL)
    {
        /* Process file content */

        /* Explicitly release file resource */
        (void)fclose(fp);[cite: 2]
        fp = NULL;
    }
}