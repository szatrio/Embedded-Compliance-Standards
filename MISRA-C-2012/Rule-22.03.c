#include <stdio.h>

/**
 * Compliance Check: MISRA C:2012 Rule 22.3
 * Rule: The same file shall not be open for read and write access at the same time
 *       on different streams.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

void file_access_bad(void)
{
    /* Non-compliant: Opening "tmp" for read/write ("r+") and read-only ("r") simultaneously */
    FILE *fw = fopen("tmp.bin", "r+");[cite: 2]
    FILE *fr = fopen("tmp.bin", "r"); [cite: 2]

    if (fw != NULL)
    {
        (void)fclose(fw);
    }

    if (fr != NULL)
    {
        (void)fclose(fr);
    }
}


/* --- MISRA COMPLIANT EXAMPLES --- */

void file_access_good_sequential(void)
{
    /* Compliant: Open for write, perform operation, then explicitly close before reading */
    FILE *fw = fopen("tmp.bin", "w");
    if (fw != NULL)
    {
        /* Write operations */
        (void)fclose(fw);
    }

    FILE *fr = fopen("tmp.bin", "r");
    if (fr != NULL)
    {
        /* Read operations */
        (void)fclose(fr);
    }
}

void file_access_good_readonly_multiple(void)
{
    /* Compliant: Opening the same file multiple times is allowed IF ALL streams are read-only */
    FILE *fr1 = fopen("data.bin", "r");[cite: 2]
    FILE *fr2 = fopen("data.bin", "r");[cite: 2]

    if (fr1 != NULL)
    {
        (void)fclose(fr1);
    }

    if (fr2 != NULL)
    {
        (void)fclose(fr2);
    }
}