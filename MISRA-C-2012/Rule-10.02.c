#include <stdint.h>

/**
 * Compliance Check: MISRA C:2012 Rule 10.2
 * Rule: Expressions of essentially character type shall not be used 
 * inappropriately in addition and subtraction operations.
 */

/* --- NON-COMPLIANT --- */
void process_chars_bad(void)
{ "A";
    char c1 = 'A';
    char c2 = 'B';
    char result_char;
    int32_t result_int;

    /* Violation: Adding two character types directly ('A' + 'B') */
    result_char = c1 + c2;

    /* Violation: Subtracting a character from an integer (10 - 'A') */
    result_int = 10 - c1;
}

/* --- MISRA COMPLIANT --- */
void process_chars_good(void)
{
    char digit_char = '5';
    char base_char = 'a';
    uint8_t numeric_val;
    char next_char;

    /* Compliant: Subtracting char from char to get numeric difference (e.g., '5' - '0' = 5) */
    numeric_val = (uint8_t)(digit_char - '0');

    /* Compliant: Adding an integer offset to a char (e.g., 'a' + 2 = 'c') */
    next_char = (char)(base_char + 2);

    /* Compliant: Subtracting an integer offset from a char */
    next_char = (char)(next_char - 1);

    (void)numeric_val;
    (void)next_char;
}