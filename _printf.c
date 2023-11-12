#include "main.h"
#include <stdio.h>

void print_buf(char buffer[], int *buf_ind);

/**
 * _printf - a custom printf function
 * @format: string with or without format specifiers
 *
 * Return: returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count, buf_ind, printed;
	va_list args;
	char buffer[BUFFER_SIZE];

	printed = 0;
	buf_ind = 0;
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			if (*format == '\n')
			{
				print_buf(buffer, &buf_ind);
				write(1, "\n", 1);
			}
			else
			{
				buffer[buf_ind++] = *format;
				if (buf_ind == BUFFER_SIZE)
					print_buf(buffer, &buf_ind);
				count++;
			}
		}
		else
		{
			print_buf(buffer, &buf_ind);
			++format;
			printed += fun_find(&format, args, buffer);
			count += printed;
		}
		format++;
	}
	return (count);
}

/**
 * print_buf - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buf_ind: Index at which to add next char, represents the length.
 */
void print_buf(char buffer[], int *buf_ind)
{
	if (*buf_ind > 0)
		write(1, &buffer[0], *buf_ind);
	*buf_ind = 0;
}
