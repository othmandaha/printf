#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int char_print = 0;
	int str_len = 0;
	va_list list_of_args;
	char *str

	if (format == NULL)
		return (-1);
	va_start(list_of_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				char_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_of_args, int);
				write(1, &c, 1);
				char_print;
			}
			else if (*format == 's')
			{
				str = va_arg(list_of_args, char*);
				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				char_print += str_len;
			}
		}
		format++;



	}
	va_end(list_of_args);
	return (char_print);
}
