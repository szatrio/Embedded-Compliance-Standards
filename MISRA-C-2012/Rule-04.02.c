#include <stdint.h>
#include <stdbool.h>

/**
 * Compliance Check: MISRA C:2012 Rule 4.2
 * Rule: Trigraphs shall not be used.
 */
void test_compliance_04_02(void) {
    
    bool is_initialization_done = true;
    uint8_t standard_flag = 0U;

    /* --- NON-COMPLIANT --- */
    /* Trigraphs (??) can be inadvertently formed, especially in strings or comments.
       The compiler preprocessor translates '??/' into a backslash '\', 
       which can accidentally join the next line or change string meanings. */
    // const char *warning_msg = "Status unknown??/";
    // standard_flag = 1U;


    /* --- MISRA COMPLIANT --- */
    /* Ensure no sequences of '??' followed by characters like '=', '/', or ')' 
       exist anywhere in the source text. */
    const char *safe_msg = "Status unknown - checking process.";
    if (is_initialization_done) {
        standard_flag = 1U;
    }
}
