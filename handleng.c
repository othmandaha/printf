#include <stdio.h>

int main() {
  // Print an integer with the `l` length modifier.
  printf("%ld\n", 1234567890);

  // Print a short integer with the `h` length modifier.
  printf("%hd\n", 12345);

  return 0;
}

void printf(const char *format, ...) {
  va_list args;
  va_start(args, format);

  while (*format != '\0') {
    if (*format == '%') {
      // Parse the format specifier.
      int conversion_specifier = *format++;
            // Check for the length modifier.
      int length_modifier = *format++;
      switch (length_modifier) {
        case 'l':
          // Use a long integer.
          break;
        case 'h':
          // Use a short integer.
          break;
        default:
          // No length modifier.
          break;
      }

      // Convert the argument.
      switch (conversion_specifier) {
        case 'd':
        case 'i':
          // Signed integer.
          long int d = va_arg(args, long int);
          if (length_modifier == 'l') {
            printf("%ld", d);
          } else if (length_modifier == 'h') {
            printf("%hd", d);
          } else {
            printf("%d", d);
          }
          break;
        case 'u':
          // Unsigned integer.
          unsigned long int u = va_arg(args, unsigned long int);
          if (length_modifier == 'l') {
            printf("%lu", u);
          } else if (length_modifier == 'h') {
            printf("%hu", u);
          } else {
            printf("%u", u);
          }
          break;
        case 'o':
          // Octal integer.
          unsigned long int o = va_arg(args, unsigned long int);
          if (length_modifier == 'l') {
            printf("%lo", o);
          } else if (length_modifier == 'h') {
            printf("%ho", o);
          } else {
            printf("%o", o);
          }
          break;
        case 'x':
        case 'X':
          // Hexadecimal integer.
          unsigned long int x = va_arg(args, unsigned long int);
          if (length_modifier == 'l') {
            printf("%lx", x);
          } else if (length_modifier == 'h') {
            printf("%hx", x);
          } else {
            printf("%x", x);
          }
          break;
        default:
          // Unknown conversion specifier.
          break;
      }
    } else {
      // Print the character.
      putchar(*format);
      format++;
    }
  }

  va_end(args);
}
