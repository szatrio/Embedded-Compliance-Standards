#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 2.4
 * Rule: A project should not contain unused tag declarations.
 */

/* --- NON-COMPLIANT EXAMPLES --- */

void unused_tag_enum_bad(void)
{
    /* Non-compliant: The tag 'state' is declared but never used */
    enum state { S_INIT, S_RUN, S_SLEEP };[cite: 1]
}

/* Non-compliant: The tag 'record_tag' is defined in typedef but never used elsewhere */
typedef struct record_tag[cite: 1]
{
    uint16_t id;
    uint16_t val;
} record1_t;[cite: 1]


/* --- MISRA COMPLIANT EXAMPLES --- */

/* Compliant Example 1: Tag 'state_tag' is declared and actually used */
enum state_tag { S_IDLE, S_BUSY };

void test_tag_good(void)
{
    enum state_tag current_state = S_IDLE;
    (void)current_state;
}

/* Compliant Example 2: Omit the tag entirely when defining typedefs if not needed */
typedef struct[cite: 1]
{
    uint16_t id;
    uint16_t val;
} record2_t;[cite: 1]

void unused_tag_enum_good(void)
{
    /* Compliant: Unused tag removed entirely */
    record2_t rec = {1U, 100U};
    (void)rec;
}