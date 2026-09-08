#include <stdint.h>
#include <stdlib.h>

/**
 * Compliance Check: MISRA C:2012 Rule 21.7
 * Rule: The atof, atoi, atol and atoll functions of <stdlib.h> shall not be used.
 */

/* --- NON-COMPLIANT EXAMPLE --- */

void convert_bad(const char *str)
{
    /* Non-compliant: atoi causes undefined behavior if conversion fails or overflows */
    int32_t val = atoi(str);
    (void)val;
}


/* --- MISRA COMPLIANT EXAMPLE --- */

/* Compliant: Alternative robust conversion using strtol with proper error checking */
int32_t convert_good(const char *str, bool_t *is_success)
{
    char *endptr = NULL;
    int32_t result = 0;

    if ((str != NULL) && (is_success != NULL))
    {
        /* Using strtol allows error checking via endptr */
        long temp = strtol(str, &endptr, 10);

        /* Check if conversion actually took place and string ended correctly */
        if ((endptr != str) && (*endptr == '\0'))
        {
            result = (int32_t)temp;
            *is_success = true;
        }
        else
        {
            *is_success = false;
        }
    }

    return result;
}