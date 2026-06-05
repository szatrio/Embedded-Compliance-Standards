
# Embedded Compliance Standards

## Overview
This repository contains compliance guidelines for embedded systems development.

## Current Standards

### MISRA C:2012
Guidelines for safe, reliable, and portable C programming.

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 4.2** | Advisory | ✅ | Trigraphs should not be used |
| **Rule 4.6** | Advisory | ✅ | Typedefs that indicate size and signedness should be used |
| **Rule 8.7** | Advisory | ✅ | Functions/objects with external linkage restrictions |
| **Rule 10.1** | Required | ✅ | Operands shall not be of an inappropriate essential type |
| **Rule 10.3** | Required | ✅ | Value shall not be assigned to a narrower essential type |
| **Rule 11.3** | Required | ✅ | Pointer cast constraints |
| **Rule 11.4** | Advisory | ✅ | Pointer to integer conversion restrictions |
| **Rule 12.1** | Advisory | ✅ | Explicit operator precedence |
| **Rule 13.2** | Required | ✅ | Consistent side effects |
| **Rule 14.4** | Required | ✅ | Boolean type for control expressions |
| **Rule 15.1** | Advisory | ✅ | No goto statement |
| **Rule 15.6** | Required | ✅ | Compound statement requirement |
| **Rule 15.7** | Required | ✅ | If-else construct termination |
| **Rule 16.4** | Required | ✅ | Switch default label mandatory |
| **Rule 17.2** | Required | ✅ | No recursion |
| **Rule 17.3** | Mandatory | ✅ | No implicit function declaration |
| **Rule 17.7** | Required | ✅ | Function return value usage |
| **Rule 18.1** | Required | ✅ | Pointer arithmetic array boundaries |
| **Rule 18.2** | Required | ✅ | Pointer subtraction array boundaries |
| **Rule 18.4** | Advisory | ✅ | Pointer operator restrictions |
| **Rule 20.7** | Required | ✅ | Macro parameter parenthesis |
| **Rule 21.1** | Required | ✅ | No reserved identifier usage |
| **Rule 21.3** | Required | ✅ | No dynamic memory (malloc/free) |


---

## Future Roadmap
- MISRA C++
- AUTOSAR
- Other industry standards

---

## Notes
- **Status**: ✅ indicates implemented rules.
- **Categories**: Required/Mandatory (Compliance) vs Advisory (Best Practice).
- **Reference**: MISRA C:2012 Appendix A.