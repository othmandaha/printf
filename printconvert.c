#include <main.h>

char *convert_base(unsigned int num, int base, bool is_signed)
{
    int i = 0;
    char *str = malloc(32);
    if (str == NULL) {
        return NULL;
    }

    while (num) {
        int digit = num % base;
        if (digit < 10) {
            str[i++] = digit + '0';
        } else {
            str[i++] = digit - 10 + 'A';
        }
        num /= base;
    }

    if (is_signed && num < 0) {
        str[i++] = '-';
    }

    str[i] = '\0';

    return str;
}
