#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include "stdio.h"
#include <string.h>
/* Function pointers for the different specifiers */
typedef void (*print_func)(va_list);

/* Function prototypes for the different specifier functions */
void print_char(va_list args);
void print_int(va_list args);
void print_string(va_list args);
void print_percent(va_list args);

/* void _printf(const char *format, ...); */
int _printf(const char *format, ...);
#endif
