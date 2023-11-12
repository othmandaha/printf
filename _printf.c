
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
	char *str;
	int c;
	va_list args;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			count += write(1, format, 1);
		}
		else
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
					str = va_arg(args, char*);
					if (str == NULL)
						count += write(1, "(null)", 6);
					else
						count += write(1, str, (strlen(str)));
					break;
				case '%':
					count += write(1, "%%", 1);
					break;
			}
		}
		format++;
	}
	return(count);
}
