#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 17.5
 * Rule: The function argument corresponding to a parameter declared
 *       to have an array type shall have an appropriate number of elements.
 */

#define REQUIRED_SIZE 5U
#define SMALL_SIZE    3U

/* Function parameter expects an array of at least REQUIRED_SIZE (5) elements */
void process_fixed_array(const uint32_t arr[REQUIRED_SIZE])
{
    uint32_t sum = 0U;
    uint32_t i;

    for (i = 0U; i < REQUIRED_SIZE; i++)
    {
        sum += arr[i]; /* Assumes arr has at least 5 elements */
    }

    (void)sum;
}


/* --- NON-COMPLIANT EXAMPLE --- */

void pass_array_bad(void)
{
    /* Non-compliant: small_buf only has 3 elements, but process_fixed_array expects 5 */
    uint32_t small_buf[SMALL_SIZE] = {1U, 2U, 3U};

    /* Calling this causes out-of-bounds access inside process_fixed_array */
    process_fixed_array(small_buf); 
}


/* --- MISRA COMPLIANT EXAMPLES --- */

void pass_array_good(void)
{
    /* Compliant: valid_buf has 5 elements, matching REQUIRED_SIZE */
    uint32_t valid_buf[REQUIRED_SIZE] = {1U, 2U, 3U, 4U, 5U};

    /* Compliant: larger_buf has 10 elements, which is >= REQUIRED_SIZE */
    uint32_t larger_buf[10] = {0U};

    process_fixed_array(valid_buf);
    process_fixed_array(larger_buf);
}