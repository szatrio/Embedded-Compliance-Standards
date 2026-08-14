#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 9.4
 * Rule: An element of an object shall not be initialized more than once.
 */

typedef struct
{
    uint8_t id;
    uint8_t status;
} DeviceConfig_t;

typedef union
{
    uint32_t raw_word;
    uint16_t half_words[2];
} DataRegister_t;

/* --- NON-COMPLIANT --- */
void test_rule_9_4_bad(void)
{
    /* Violation: Index 0 is initialized twice using designated initializers */
    uint8_t array_bad[3] = { [0] = 1U, [1] = 2U, [0] = 3U };

    /* Violation: Member 'id' is explicitly initialized twice */
    DeviceConfig_t dev_bad = { .id = 1U, .status = 0U, .id = 2U };

    /* Violation: Initializing multiple members of a union in the same initializer list */
    DataRegister_t reg_bad = { .raw_word = 0x12345678U, .half_words = { 0x5678U, 0x1234U } };
}

/* --- MISRA COMPLIANT --- */
void test_rule_9_4_good(void)
{
    /* Compliant: Each array element is initialized exactly once */
    uint8_t array_good[3] = { 3U, 2U, 0U };

    /* Compliant: Each struct member is initialized once */
    DeviceConfig_t dev_good = { .id = 2U, .status = 0U };

    /* Compliant: Only one member of a union is initialized */
    DataRegister_t reg_good = { .raw_word = 0x12345678U };
}