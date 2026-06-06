
# Embedded Compliance Standards

## Overview
This repository contains compliance guidelines for embedded systems development.

## Current Standards

### MISRA C:2012
Guidelines for safe, reliable, and portable C programming.

#### 1. A standard C environment

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 1.1** | Required |  | The program shall contain no violations of the standard C syntax and constraints, and shall not exceed the implementation’s translation limits |
| **Rule 1.2** | Advisory |  | Language extensions should not be used |
| **Rule 1.3** | Required |  | There shall be no occurrence of undefined or critical unspecified behaviour |

#### 2. Unused code

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 2.1** | Required |  | A project shall not contain unreachable code |
| **Rule 2.2** | Required |  | There shall be no dead code |
| **Rule 2.3** | Advisory |  | A project should not contain unused type declarations |
| **Rule 2.4** | Advisory |  | A project should not contain unused tag declarations |
| **Rule 2.5** | Advisory |  | A project should not contain unused macro declarations |
| **Rule 2.6** | Advisory |  | A function should not contain unused label declaration |
| **Rule 2.7** | Advisory |  | There should be no unused parameters in functions |

#### 3. Comments

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 3.1** | Required |  | The character sequences /* and // shall not be used within a comment |
| **Rule 3.2** | Required |  | Line-splicing shall not be used in // comments |


#### 4. Unused code

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 4.1** | Required |  | Octal and hexadecimal escape sequences shall be terminated |
| **Rule 4.2** | Advisory |  | Trigraphs should not be used |

#### 5. Identifiers

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 5.1** | Required |  | External identifiers shall be distinct |
| **Rule 5.2** | Required |  | Identifiers declared in the same scope and name space shall be distinct |
| **Rule 5.3** | Required |  | An identifier declared in an inner scope shall not hide an identifier declared in an outer scope |
| **Rule 5.4** | Required |  | Macro identifiers shall be distinct |
| **Rule 5.5** | Required |  | Identifiers shall be distinct from macro names |
| **Rule 5.6** | Required |  | A typedef name shall be a unique identifier |
| **Rule 5.7** | Required |  | A tag name shall be a unique identifier |
| **Rule 5.8** | Required |  | Identifiers that define objects or functions with external linkage shall be unique |
| **Rule 5.9** | Advisory |  | Identifiers that define objects or functions with internal linkage should be unique |

#### 6. Types

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 6.1** | Required |  | Bit-fields shall only be declared with an appropriate type |
| **Rule 6.2** | Required |  | Single-bit named bit fields shall not be of a signed type |

#### 7. Literals and constants

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 7.1** | Required |  | Octal constants shall not be used |
| **Rule 7.2** | Required |  | A “u” or “U” suffix shall be applied to all integer constants that are represented in an unsigned type |
| **Rule 7.3** | Required |  | The lowercase character “l” shall not be used in a literal suffix |
| **Rule 7.4** | Required |  | A string literal shall not be assigned to an object unless the object’s type is “pointer to const-qualified char” |

#### 8. Declarations and definitions

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 8.1** | Required |  | Types shall be explicitly specified |
| **Rule 8.2** | Required |  | Function types shall be in prototype form with named parameter |
| **Rule 8.3** | Required |  | All declarations of an object or function shall use the same names and type qualifiers |
| **Rule 8.4** | Required |  | A compatible declaration shall be visible when an object or function with external linkage is defined |
| **Rule 8.5** | Required |  | An external object or function shall be declared once in one and only one file |
| **Rule 8.6** | Required |  | An identifier with external linkage shall have exactly one external definition |
| **Rule 8.7** | Advisory |  | Functions and objects should not be defined with external linkage if they are referenced in only one translation unit |
| **Rule 8.8** | Required |  | The static storage class specifier shall be used in all declarations of objects and functions that have internal linkage |
| **Rule 8.9** | Advisory |  | An object should be defined at block scope if its identifier only appears in a single function |
| **Rule 8.10** | Required |  | An inline function shall be declared with the static storage class |
| **Rule 8.11** | Advisory |  | When an array with external linkage is declared, its size should be explicitly specified |
| **Rule 8.12** | Required |  | Within an enumerator list, the value of an implicitly-specified enumeration constant shall be unique |
| **Rule 8.13** | Advisory |  | A pointer should point to a const-qualified type whenever possible |
| **Rule 8.14** | Required |  | The restrict type qualifier shall not be used |

#### 9. Initialization

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 9.1** | Mandatory |  | The value of an object with automatic storage duration shall not be read before it has been set |
| **Rule 9.2** | Required |  | The initializer for an aggregate or union shall be enclosed in braces |
| **Rule 9.3** | Required |  | Arrays shall not be partially initialized |
| **Rule 9.4** | Required |  | An element of an object shall not be initialized more than once |
| **Rule 9.5** | Required |  | Where designated initializers are used to initialize an array object the size of the array shall be specified explicitly |

#### 10. The essential type model

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 10.1** | Required |  | Operands shall not be of an inappropriate essential type |
| **Rule 10.2** | Required |  | Expressions of essentially character type shall not be used inappropriately in addition and subtraction operations |
| **Rule 10.3** | Required |  | The value of an expression shall not be assigned to an object with a narrower essential type or of a different essential type category |
| **Rule 10.4** | Required |  | Both operands of an operator in which the usual arithmetic conversions are performed shall have the same essential type category |
| **Rule 10.5** | Advisory |  | The value of an expression should not be cast to an inappropriate essential type |
| **Rule 10.6** | Required |  | The value of a composite expression shall not be assigned to an object with wider essential type |
| **Rule 10.7** | Required |  | If a composite expression is used as one operand of an operator in which the usual arithmetic conversions are performed then the other operand shall not have wider essential type |
| **Rule 10.8** | Required |  | The value of a composite expression shall not be cast to a different essential type category or a wider essential type |

#### 11. Pointer type conversions

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 11.1** | Required |  | Conversions shall not be performed between a pointer to a function and any other type |
| **Rule 11.2** | Required |  | Conversions shall not be performed between a pointer to an incomplete type and any other type |
| **Rule 11.3** | Required |  | A cast shall not be performed between a pointer to object type and a pointer to a different object type |
| **Rule 11.4** | Advisory |  | A conversion should not be performed between a pointer to object and an integer type |
| **Rule 11.5** | Advisory |  | A conversion should not be performed from pointer to void into pointer to object |
| **Rule 11.6** | Required |  | A cast shall not be performed between pointer to void and an arithmetic type |
| **Rule 11.7** | Required |  | A cast shall not be performed between pointer to object and a non- integer arithmetic type |
| **Rule 11.8** | Required |  | A cast shall not remove any const or volatile qualification from the type pointed to by a pointer |
| **Rule 11.9** | Required |  | The macro NULL shall be the only permitted form of integer null pointer constant |

#### 12. Expressions

| Rule ID | Category | Status | Rule Title |
| :--- | :--- | :--- | :--- |
| **Rule 12.1** | Advisory |  | The precedence of operators within expressions should be made explicit |
| **Rule 12.2** | Required |  | The right hand operand of a shift operator shall lie in the range zero to one less than the width in bits of the essential type of the left hand operand |
| **Rule 12.3** | Advisory |  | The comma operator should not be used |
| **Rule 12.4** | Advisory |  | Evaluation of constant expressions should not lead to unsigned integer wrap-around |

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