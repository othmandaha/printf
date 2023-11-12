#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: pointer to the coresponding function
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[]);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated with it.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int fun_find(const char **fmt, va_list args, char buffer[]);
int print_char(va_list args, char buffer[]);
int print_percent(va_list args, char buffer[]);
int print_string(va_list args, char buffer[]);




#endif
