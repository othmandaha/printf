#include "main.h"

/**
 * print_number - prints an integer.
 * @num: input integer.
 * Return: length of digit.
 */

int print_number(int num)
{
	unsigned int abs_num = num > 0 ? num : -num;
	char *str = convert_base(abs_num, 10, false);
	int len = 0;

	if (num == 0)
		return (_putchar('0'));

	if (num < 0)
		len += _putchar('-');

	len += print_string(str);

	free(str);

	return (len);
}
