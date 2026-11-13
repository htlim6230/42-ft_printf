*This project has been created as part of the 42 curriculum by hui-tinl*

# ft_printf

## Description

**ft_printf** is a custom implementation of the standard C library function `printf`. The goal of this project is to recreate the core formatted output functionality of `printf` from scratch, deepening an understanding of variadic functions (`stdarg.h`), type casting, number base conversions, and modular C programming under strict memory and Norminette constraints (including the 25-line limit per function).

Rather than relying on standard high-level formatting utilities, this implementation handles output at a low level using only the `write` system call, recursive base decomposition, `while` loops, and conditional (`if`/`else`) routing. It parses a format string character by character, dispatches format specifiers via a `va_list` pointer, and accurately tracks and returns the total number of characters printed to standard output.

### Supported Conversions

* `%c` — Prints a single character.
* `%s` — Prints a string (as defined by the common C convention, handling `NULL` pointers safely).
* `%p` — Prints a `void *` pointer address in lowercase hexadecimal format prefixed with `0x` (or `(nil)` for null pointers).
* `%d` — Prints a signed decimal (base 10) number.
* `%i` — Prints a signed integer in base 10.
* `%u` — Prints an unsigned decimal (base 10) number.
* `%x` — Prints a number in lowercase hexadecimal (base 16) format.
* `%X` — Prints a number in uppercase hexadecimal (base 16) format.
* `%%` — Prints a literal percent sign.

---

## Instructions

### Compilation

The project includes a `Makefile` that compiles the source files with `-Wall -Wextra -Werror` and archives them into a static library named `libftprintf.a`.

The project includes a GNU `Makefile` that compiles all sources using `cc` (or `clang`) with the mandatory `-Wall -Wextra -Werror` flags.

| Command | Action |
| --- | --- |
| `make` / `make all` | Compiles `.c` sources into `.o` objects and creates the `libftprintf.a` static library. |
| `make clean` | Removes compiled object files (`.o`). |
| `make fclean` | Removes compiled object files (`.o`) and the `libft.a` library. |
| `make re` | Performs `fclean` followed by `all` to execute a fresh build. |

Usage & Execution
To use ft_printf in your own C project, include the header file in your source code:
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf 
./test_printf

## Resources
1. **Classic References**
Linux Manual Pages (man 3 printf, man 3 stdarg, man 2 write) — Official documentation detailing standard printf return behaviors, variadic macro mechanics (va_start, va_arg, va_end), and file descriptor output.

The C Programming Language (2nd Edition) by Brian W. Kernighan & Dennis M. Ritchie — Reference for variadic argument lists, default argument promotions in C, and recursive integer-to-character conversion.

42 Norminette Documentation — Guidelines for function length limits (25 lines max), variable declarations, and modular file organization.

### AI Collaboration Disclosure
AI assistance was utilized as a debugging and architectural sounding board during development, specifically for the following tasks:

* **Architectural Refactoring (Norminette Compliance):** Designing a modular dispatcher pattern (ft_print_inst) that passes a va_list * pointer across helper functions so ft_printf stays within 42's 25-line function limit without losing variadic argument progression.

* **Debugging & Edge-Case Analysis:** Identifying issues related to C's default variadic argument promotion rules (e.g., retrieving char arguments as int before casting), resolving double-printing and return-value tracking (tracker) bugs, and diagnosing 64-bit pointer truncation (unsigned long long vs. unsigned int) in the %p hexadecimal conversion.

* **Build Configuration & Documentation:** Troubleshooting Makefile syntax/target errors and structuring this README.md documentation.

