#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
int _printf(const char *format, ...);
int get_specifier(va_list list, char src, char *dest, int index);
#endif /* !MAIN_H */
