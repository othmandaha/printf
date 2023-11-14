#include "main.h"

/**
 * print_string - prints a string
 * @str: string
 * Return: length of string
 */

int print_string(const char *str)
{
	int i, len = 0;

	if (!str)
{
		len = 5;
		for (i = 0; i < len; i++)
		{
			_putchar("("(null)"[i]);
		}
}
	else
	{
	while (*str)
	{
		_putchar(*str);
		len++;
		str++;
	}
	}

return (len);
}
