#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int handle_char(va_list args, buffer[]);
int print_char(const char **format, char buffer[], int count);
int handle_percent(va_list args, char buffer[], int count);
int handle_string(va_list args, char buffer[], int count);




#endif
