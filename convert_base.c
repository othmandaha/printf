#include "main.h"

/**
 * convert_base - convert a number to a base
 *
 * @number: number to convert
 * @base: base to convert to
 * @upper: whether to use upper or lower case
 *
 * Return: converted number
 */

char *convert_base(unsigned long number, int base, bool upper)
{
	char *digits = upper ? "0123456789ABCDEF" : "0123456789abcdef";
	char *result;
	int len = number ? 0 : 1;
	unsigned long index;

	for (index = number; index > 0; index /= base)
		len++;

	result = calloc(len + 1, sizeof(char));
	if (result == NULL)
		exit(1);

	index = len - 1;
	while (number > 0)
	{
		result[index] = digits[number % base];
		number /= base;
		index--;
	}

	result[len] = '\0';

	return (result);
}
