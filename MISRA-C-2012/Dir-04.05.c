#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Directive 4.5
 * Directive: Identifiers in the same name space with overlapping visibility
 *            should be typographically unambiguous.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

/* Non-compliant: Identifiers differ only by lowercase/uppercase or underscore placement */
static int32_t id1_a_b_c;
static int32_t id1_abc;   /* Non-compliant: Ambiguous with id1_a_b_c */

/* Non-compliant: Identifiers differ only by visually similar characters ('O' vs '0', 'l' vs '1') */
static int32_t id_O_val;
static int32_t id_0_val;   /* Non-compliant: Ambiguous due to 'O' and '0' confusion */

static int32_t id_l_val;
static int32_t id_1_val;   /* Non-compliant: Ambiguous due to 'l' and '1' confusion */


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant: Identifiers have distinct and unambiguous names within the same visibility scope */
static int32_t sensor_primary_value;
static int32_t sensor_secondary_value;

/* Compliant: Identifiers in different scopes or clearly distinct naming patterns */
void process_identifiers_good(void)
{
    /* Compliant: Unambiguous identifier names with clear meaning */
    uint32_t buffer_index = 0U;
    uint32_t buffer_count = 10U;

    (void)buffer_index;
    (void)buffer_count;
}