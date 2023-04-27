#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_specifier(va_list list, char specifier);
int _putchar(char c);
int print_char(va_list list);
int print_string(va_list list);
int print_int(va_list list);
#endif /* !MAIN_H */
