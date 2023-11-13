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

