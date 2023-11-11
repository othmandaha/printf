`#include "main.h"
#include <unistd.h>

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

            if (*format != 'c' && *format != 's' && *format != '%')
            {
                return -1;
            }

            switch (*format)
            {
                case 'c':
                    buffer[buf_index++] = (char)va_arg(args, int);
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char*);
                        if (str == NULL)
                            buf_index += snprintf(buffer + buf_index, sizeof(buffer) - buf_index, "(null)");
                        else
                            buf_index += snprintf(buffer + buf_index, sizeof(buffer) - buf_index, "%s", str);
                    }
                    break;
                case '%':
                    buffer[buf_index++] = '%';
                    break;
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
`
