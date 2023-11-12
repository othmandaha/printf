#include "main.h"

/**
 * print_char - Prints a char
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 *
 * Return: number of chars
 */

int print_char(va_list args, char buffer[])
{
	int i;
	char c;

	c = va_arg(args, int);
	i = 0;
	buffer[i++] = c;
	buffer[i] = '\0';

	return (write(1, &buffer[0], 1));
}
/**
 * print_percent - Prints percent
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 *
 * Return: number of chars
 */

int print_percent(va_list args, char buffer[])
{
	UNUSED(args);
	UNUSED(buffer);

	return (write(1, "%%", 1));
}

/**
 * print_string - Prints a string
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 *
 * Return: number of chars
 */

int print_string(va_list args, char buffer[])
{

	int length;
	char *str;

	UNUSED(buffer);
	str = va_arg(args, char*);
	length = 0;

	if (str == NULL)
		str = "(null)";
	while (str[length] != '\0')
		length++;

	return (write(1, str, length));
}
