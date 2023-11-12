#include "main.h"

/**
 * fun_find - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @args: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 *
 * Return: 1 or -1
 */

int fun_find(const char **fmt, va_list args, char buffer[])
{
	int i;
	int inco_len = 0;
	int printed_char;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'\0', NULL}
	};
	printed_char = -1;

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (**fmt == fmt_types[i].fmt)
			return (fmt_types[i].fn(args, buffer));
	}

	if (fmt_types[i].fmt == '\0')
	{
		if (**fmt == '\0')
			return (-1);
		inco_len += write(1, "%%", 1);
		if (**fmt-- == ' ')
			inco_len += write(1, " ", 1);
		inco_len += write(1, *fmt, 1);
		return (inco_len);
	}
	return (printed_char);
}
