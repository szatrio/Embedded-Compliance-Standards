#include <stdint.h>
#include <stddef.h>

/**
 * Compliance Check: MISRA C:2012 Rule 18.7
 * Rule: Flexible array members shall not be declared.
 */

#define MAX_DATA_SIZE  10U

/* Non-compliant example */
struct bad_packet
{
    uint16_t len;
    uint32_t data[]; /* Non-compliant: flexible array member */
};

/* Compliant example */
struct good_packet
{
    uint16_t len;
    uint32_t data[MAX_DATA_SIZE]; /* Compliant: fixed size array */
};

void test_rule_18_7_bad(void)
{
    struct bad_packet pkt1;
    pkt1.len = 0U;
    
    /* Avoid using bad_packet */
    (void)pkt1;
}

void test_rule_18_7_good(void)
{
    struct good_packet pkt2 = {0};
    pkt2.len = 1U;
    pkt2.data[0] = 100U;

    (void)pkt2;
}