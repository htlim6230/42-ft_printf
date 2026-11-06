# 42-ft_printf

c2r2s3% cc -Wall -Wextra -Werror ft_printf.c
In file included from ft_printf.c:16:
./ft_printf.h:13:2: error: invalid preprocessing directive
#infdef FT_PRINTF_H
 ^
./ft_printf.h:22:2: error: #endif without #if
#endif
 ^
ft_printf.c:50:11: error: implicit declaration of function 'ft_putnbr' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
                return (ft_putnbr(va_arg(args, int)));
                        ^
ft_printf.c:50:11: note: did you mean 'ft_putstr'?
ft_printf.c:26:5: note: 'ft_putstr' declared here
int     ft_putstr(char *s)
        ^
ft_printf.c:52:11: error: implicit declaration of function 'ft_putdec' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
                return (ft_putdec(va_arg(args, double)));
                        ^
ft_printf.c:54:11: error: implicit declaration of function 'ft_puthex' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
                return (ft_puthex(&str[i], va_arg(args, unsigned int)));
                        ^
ft_printf.c:54:11: note: did you mean 'ft_putdec'?
ft_printf.c:52:11: note: 'ft_putdec' declared here
                return (ft_putdec(va_arg(args, double)));
                        ^
ft_printf.c:56:11: error: implicit declaration of function 'ft_point_hex' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
                return (ft_point_hex(va_args(args, void *)));
                        ^
ft_printf.c:56:11: note: did you mean 'ft_puthex'?
ft_printf.c:54:11: note: 'ft_puthex' declared here
                return (ft_puthex(&str[i], va_arg(args, unsigned int)));
                        ^
ft_printf.c:56:24: error: implicit declaration of function 'va_args' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
                return (ft_point_hex(va_args(args, void *)));
                                     ^
ft_printf.c:56:38: error: expected expression
                return (ft_point_hex(va_args(args, void *)));
                                                   ^
ft_printf.c:59:13: error: incompatible integer to pointer conversion passing 'int' to parameter of type 'const void *' [-Werror,-Wint-conversion]
                write (1, '%', 1);
                          ^~~
/usr/include/unistd.h:378:45: note: passing argument to parameter '__buf' here
extern ssize_t write (int __fd, const void *__buf, size_t __n) __wur
                                            ^
ft_printf.c:46:35: error: second argument to 'va_arg' is of promotable type 'char'; this va_arg has undefined behavior because arguments will be promoted to 'int' [-Werror,-Wvarargs]
                return (ft_putchar(va_arg(args, char)));
                                                ^~~~
/usr/lib/llvm-12/lib/clang/12.0.1/include/stdarg.h:19:50: note: expanded from macro 'va_arg'
#define va_arg(ap, type)    __builtin_va_arg(ap, type)
                                                 ^~~~
ft_printf.c:76:18: error: incompatible pointer types passing 'va_list' (aka '__builtin_va_list') to parameter of type 'const char *' [-Werror,-Wincompatible-pointer-types]
                        ft_print_inst(args);
                                      ^~~~
ft_printf.c:39:31: note: passing argument to parameter 'str' here
int     ft_print_inst(const char *str, ...)
                                  ^
ft_printf.c:80:4: error: use of undeclared identifier 'tracker'
                        tracker += ft_putchar(str[i]);
                        ^
12 errors generated.
