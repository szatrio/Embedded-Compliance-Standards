#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 12.4
 * Rule: Evaluation of constant expressions should not lead to
 *       unsigned integer wrap-around.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: 0U - 1U causes unsigned integer wrap-around to UINT32_MAX */
#define INVALID_TIMEOUT (0U - 1U)

void constant_wrap_bad(void)
{
    /* Non-compliant: Constant evaluation wraps around UINT8_MAX (255) to 4 */
    uint8_t max_buf = (uint8_t)(250U + 10U);

    (void)max_buf;
}


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Use explicit maximum macro instead of underflow trick */
#define VALID_TIMEOUT UINT32_MAX

void constant_wrap_good(void)
{
    /* Compliant: Constant expression evaluated within valid uint8_t bounds (0 - 255) */
    uint8_t max_buf = 250U + 5U;

    (void)max_buf;
}