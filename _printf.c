`#include "main.h"
#include <unistd.h>

void append_str_to_buffer(const char *str, char *buffer, int *buf_index) {
    while (*str) {
        buffer[(*buf_index)++] = *str++;

        if (*buf_index == sizeof(buffer) - 1) {
            write(1, buffer, *buf_index);
            *buf_index = 0;
        }
    }
}

int _printf(const char *format, ...)
{
    char buffer[1024];
    int count = 0;
    int buf_index = 0;

    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            buffer[buf_index++] = *format;

            if (buf_index == sizeof(buffer) - 1)
            {
                count += write(1, buffer, buf_index);
                buf_index = 0;
            }
        }
        else
        {
            format++;

            if (*format == 'c')
            {
                buffer[buf_index++] = (char)va_arg(args, int);
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char*);
                const char *output = (str == NULL) ? "(null)" : str;
                append_str_to_buffer(output, buffer, &buf_index);
            }
            else if (*format == '%')
            {
                buffer[buf_index++] = '%';

                if (buf_index == sizeof(buffer) - 1)
                {
                    count += write(1, buffer, buf_index);
                    buf_index = 0;
                }
            }
            else
            {
                return -1;  // Unsupported format specifier
            }
        }

        format++;
    }

    if (buf_index > 0)
    {
        count += write(1, buffer, buf_index);
    }

    va_end(args);
    return count;
}
