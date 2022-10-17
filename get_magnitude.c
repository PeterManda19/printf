#include "main.h"

/**
 * get magnitude - Calculates the magnitude of the argument's cast
 * @format: Formatted string to print the arguments in
 * @i: Arguments array to be printed.
 *
 * Return: Magnitude.
 */
int get magnitude(const char *format, int *i)
{
	int curr_i = *i + 1;
	int magnitude = 0;

	if (format[curr_i] == 'l')
	 magnitude = S_LONG;
	else if (format[curr_i] == 'h')
	 magnitude = S_SHORT;

	if  (magnitude == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return  (magnitude);
}
