#include "main.h"

/**
 * _printf - a custom printf function
 * @format: string with or without format specifiers
 *
 * Return: returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			count += print_char(&format, buffer, count);
		}
		else
		{
			format++;
			if (*format != 'c' && *format != 's' && *format != '%')
				return (-1);
			switch (*format)
			{
				case 'c':
					count += handle_char(args, buffer, count);
					break;
				case 's':
					count += handle_string(args, buffer, count);
					break;
				case '%':
					count += handle_percent(buffer, count);
					break;
			}
		}
		format++;
	}
	write(1, buffer, count);
	return (count);
}
