#include <stdint.h>
#include <stdio.h>

/**
 * Compliance Check: MISRA C:2012 Rule 20.6
 * Rule: Tokens that look like a preprocessing directive shall not occur
 *       within a macro argument.
 */

#define PRINT_MSG(msg) printf("%s\n", (msg))

void test_rule_20_6_bad(void)
{
    /* Non-compliant: Passing a preprocessor directive inside a macro argument */
    PRINT_MSG(
#ifdef DEBUG
        "Debug Mode"
#else
        "Release Mode"
#endif
    );
}

void test_rule_20_6_good(void)
{
    /* Compliant: Move preprocessor conditional logic outside macro invocation */
#ifdef DEBUG
    const char *mode = "Debug Mode";
#else
    const char *mode = "Release Mode";
#endif

    PRINT_MSG(mode);
}