#include "main.h"

/**
 * _printf - prints a formatted string to stdout
 * @format: format string
 * @...: arguments
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, chars_count = 0;

	if (format == NULL || (_strlen(format) == 1 && format[0] == '%'))
		return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					chars_count += _putchar(va_arg(args, int));
					break;
				case 's':
					chars_count += print_string(va_arg(args, char *));
					break;
				case '%':
					chars_count += _putchar('%');
					break;
				case 'i':
				case 'd':
					chars_count += print_number(va_arg(args, int));
					break;
				case 'b':
					chars_count += print_binary(va_arg(args, unsigned int));
					break;
				default:
					chars_count += print_invalid(format[i]);
			}
		}
		else
			chars_count += _putchar(format[i]);
	}

	va_end(args);

	return (chars_count);
}
