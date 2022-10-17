#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: array a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @breadth: breadth
 * @accuracy: accuracy specification
 * @magnitude: magnitude specifier
 * Return: Number of chars printed
 */
int print_char(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, breadth, accuracy, magnitude));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: array a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth.
 * @accuracy: accuracy specification
 * @magnitude: magnitude specifier
 * Return: Number of chars printed
 */
int print_string(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(breadth);
	UNUSED(accuracy);
	UNUSED(magnitude);
	if (str == NULL)
	{
		str = "(null)";
		if (accuracy >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (accuracy >= 0 && accuracy < length)
		length = accuracy;

	if (breadth > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = breadth - length; i > 0; i--)
				write(1, " ", 1);
			return (breadth);
		}
		else
		{
			for (i = breadth - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (breadth);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: arraya of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth.
 * @accuracy: accuracy specification
 * @magnitude: magnitude specifier
 * Return: Number of chars printed
 */
int print_percent(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(breadth);
	UNUSED(accuracy);
	UNUSED(magnitude);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: arraya of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth.
 * @accuracy: accuracy specification
 * @magnitude: magnitude specifier
 * Return: Number of chars printed
 */
int print_int(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude)
{
	int i = BUFF_magnitude - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_magnitude_number(n, magnitude);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_magnitude - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, breadth, accuracy, magnitude));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: arraya of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth.
 * @accuracy: accuracy specification
 * @magnitude: magnitude specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(breadth);
	UNUSED(accuracy);
	UNUSED(magnitude);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
