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
	int c;
	char *str;
	va_list args;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format != 'c' && *format != 's' && *format != '%')
				return (-1);
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					count += write(1, &c, 1);
					break;
				case 's':
					str = va_arg(args, char *);
					count += write(1, str, strlen(str));
					break;
				case '%':
					c = '%';
					count += write(1, &c, 1);
					break;
			}
		}
		else
		{
			c = *format;
			count += write(1, &c, 1);
		}
		format++;
	}
	return (count);
}
