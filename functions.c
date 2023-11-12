#include "main.h"

/**
 * print_char - handles printing normal characters
 * @format: pointer to the current position in the format string
 * @buffer: buffer array to store the character
 * @count: current count of characters in the buffer
 *
 * Return: returns the number of characters handled
 */
int print_char(const char **format, char buffer[], int count)
{
	char c;
	int index;
	int i;
	if (**format != '\0')
	{
		c = **format;
		if (count < BUFFER_SIZE - 1)
		{
			index = count;
			buffer[index] = c;
			count++;
			return (1);
		}
		else
		{
			index = 0;
			write(1, buffer, BUFFER_SIZE - 1);
			for (i = 0; i < BUFFER_SIZE; i++)
			{
				buffer[i] = '\0';
			}
			buffer[index] = c;
			count++;
			return (1);
		}
	}
	else
		return(0);
}

/**
 * handle_char - handles c format specifier
 * @args: list of arguments
 * @buffer: buffer array to store the character
 * @count: current count of characters in the buffer
 *
 * Return: returns the number of characters handled
 */
int handle_char(va_list args, char buffer[], int count)
{
	char c;
	int index;
	int i;

	c = va_arg(args, int);
	if (count < BUFFER_SIZE - 1)
	{
		index = count;
		buffer[index] = c;
		count++;
		return (1);
	}
	else
	{
		index = 0;
		write(1, buffer, BUFFER_SIZE - 1);
		for (i = 0; i < BUFFER_SIZE; i++)
		{
			buffer[i] = '\0';
		}
		buffer[index] = c;
		return (1);
	}
}

/**
 * handle_percent - handles percent format specifier
 * @args: list of arguments
 * @buffer: buffer array to store the percent sign
 * @count: current count of characters in the buffer
 *
 * Return: returns the number of characters handled
 */
int handle_percent(char buffer[], int count)
{
	int index;
	int i;

	if (count < BUFFER_SIZE - 1)
	{
		index = count;
		buffer[index] = '%';
		count++;
		return (1);
	}
	else
	{
		index = 0;
		write(1, buffer, BUFFER_SIZE - 1);
		for (i = 0; i < BUFFER_SIZE; i++)
		{
			buffer[i] = '\0';
		}
		buffer[index] = '%';
		count++;
		return (1);
	}
}

/**
 * handle_string - handles string format specifier
 * @args: list of arguments
 * @buffer: buffer array to store the string
 * @count: current count of characters in the buffer
 *
 * Return: returns the number of characters handled
 */
int handle_string(va_list args, char buffer[], int count)
{
	int len;
	int index;
	char *str;
	int j;
	int i;

	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	len = strlen(str);


	if ((count + len) < BUFFER_SIZE - 1)
	{
		index = count;
		for (j = 0; j < len; j++)
		{
			buffer[index] = str[j];
			index++;
		}
		count++;
		return (len);
	}
	else
	{
		index = 0;
		write(1, buffer, BUFFER_SIZE - 1);
		for (i = 0; i < BUFFER_SIZE; i++)
		{
			buffer[i] = '\0';
		}
		for (j = 0; j < len; j++)
		{
			buffer[index] = str[j];
			index++;
		}
		count++;
		return (len);
	}
}
