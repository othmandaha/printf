#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...)
{
	int count;
	int c;
	char *str;
	va_list args;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					count++;
					write(1, &c, 1);
					break;	
				case 's':
					str = va_arg(args, char *);
					count += strlen(str);
					write(1, str, strlen(str));
					break;
				case '%':
					c = '%';
					count++;
					write(1, &c, 1);
					break;	
			}
		}
		else
		{
			c = *format;
			count++;
			write(1, &c, 1);
		}
		format++;
	}
	return (count);
}
