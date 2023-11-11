#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_buffer - prints the contents of the buffer and resets the index
 * @buffer: the buffer to be printed
 * @buff_ind: pointer to the buffer index, will be reset to 0 after printing
 */
void print_buffer(char buffer[], int *buff_ind)
{
	write(1, buffer, *buff_ind);
	*buff_ind = 0;
}

/**
 * _printf - a custom printf function with a buffer
 * @format: string with or without format specifiers
 *
 * Return: returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			if (buffer_index == BUFFER_SIZE - 1)
			{
				print_buffer(buffer, &buffer_index);
			}

			buffer[buffer_index++] = *format;
			count++;
		}
		else
		{
			format++;
			if (*format != 'c' && *format != 's' && *format != '%')
				return (-1);

			switch (*format)
			{
			case 'c':
				if (buffer_index == BUFFER_SIZE - 1)
				{
					print_buffer(buffer, &buffer_index);
				}

				buffer[buffer_index++] = va_arg(args, int);
				count++;
				break;

			case 's':
				{
					const char *str = va_arg(args, const char *);
					size_t len = strlen(str);

					if (buffer_index + len >= BUFFER_SIZE)
					{
						print_buffer(buffer, &buffer_index);
					}

					memcpy(buffer + buffer_index, str, len);
					buffer_index += len;
					count += len;
				}
				break;

			case '%':
				if (buffer_index == BUFFER_SIZE - 1)
				{
					print_buffer(buffer, &buffer_index);
				}

				buffer[buffer_index++] = '%';
				count++;
				break;
			}
		}
		format++;
	}

	print_buffer(buffer, &buffer_index);

	va_end(args);

	return (count);
}

