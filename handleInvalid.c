#include "main.h"

/**
 * print_invalid - prints an invalid format specifier
 * @c : specifier
 * Return: number of bytes printed
 */

int print_invalid(char c)
{
	int len = 0;

	len += _putchar('%');
	len += _putchar(c);

	return (len);
}
