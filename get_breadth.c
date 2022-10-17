#include "main.h"

/**
 * get_breadth - Calculates the breadth for printing
 * @format: Formatted string in which to print the arguments.
 * @i: array of arguments to be printed.
 * @array: array of arguments.
 *
 * Return: breadth.
 */
int get_breadth(const char *format, int *i, va_array array)
{
	int curr_i;
	int breadth = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			breadth *= 10;
			breadth += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			breadth = va_arg(array, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (breadth);
}
