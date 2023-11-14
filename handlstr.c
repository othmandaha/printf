#include "main.h"

/**
 * print_string - prints a string
 * @str: string
 * Return: length of string
 */

int print_string(const char *str)
{
	int chars_count = 0;

	while (*str)
	{
		if ((int)*str < 32 || (int)*str >= 127)
		{
			chars_count += print_number((int)*str);
			chars_count += _putchar('\\');
			chars_count += _putchar('x');
		}
			else
			{
			chars_count += _putchar(*str);
			}
			str++;
	}

	return (chars_count);
}
