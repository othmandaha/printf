#ifndef PRINTF_HEADER_H
#define PRINTF_HEADER_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

char *convert_base(unsigned int num, int base, bool is_signed);
int _putchar(char c);
size_t _strlen(const char *str);
int print_string(const char *str);
int print_invalid(char c);
int print_number(int num);
int print_binary(unsigned int n);
char *convert_base(unsigned long number, int base, bool upper);

int _printf(const char *format, ...);

#endif
