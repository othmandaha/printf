#include "main.h"
#include <stdio.h>

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

int main(void)
{
    int result1, result2;

    /* Test case 1: Basic string */
    result1 = printf("hello %s!\n", "world");
    result2 = _printf("hello %s!\n", "world");
    printf("Real printf result: %d\n", result1);
    printf("Your _printf result: %d\n", result2);

    /* Test case 2: Character */
    result1 = printf("%c\n", 'A');
    result2 = _printf("%c\n", 'A');
    printf("Real printf result: %d\n", result1);
    printf("Your _printf result: %d\n", result2);

    /* Test case 3: Percent sign */
    result1 = printf("%%\n");
    result2 = _printf("%%\n");
    printf("Real printf result: %d\n", result1);
    printf("Your _printf result: %d\n", result2);

    /* Test case 4: NULL string */
    result1 = printf("%s\n", "(null)");
    result2 = _printf("%s\n", "(null)");
    printf("Real printf result: %d\n", result1);
    printf("Your _printf result: %d\n", result2);

    return 0;
}


