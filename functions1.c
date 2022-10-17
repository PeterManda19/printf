#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: array a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @accuracy: accuracy specification
 * @magnitude: magnitude specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude)
{
	int i = BUFF_magnitude - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_magnitude_unsgnd(num, magnitude);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_magnitude - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, breadth, accuracy, magnitude));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: arraya of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @accuracy: accuracy specification
 * @magnitude: magnitude specifier
 * Return: Number of chars printed
 */
int print_octal(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude)
{

	int i = BUFF_magnitude - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(breadth);

	num = convert_magnitude_unsgnd(num, magnitude);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_magnitude - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, breadth, accuracy, magnitude));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: arraya of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @accuracy: accuracy specification
 * @magnitude: magnitude specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', breadth, accuracy, magnitude));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: arraya of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @breadth: get breadth
 * @accuracy: accuracy specification
 * @magnitude: magnitude specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', breadth, accuracy, magnitude));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: arraya of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @breadth: get breadth
 * @accuracy: accuracy specification
 * @magnitude: magnitude specifier
 * @magnitude: magnitude specification
 * Return: Number of chars printed
 */
int print_hexa(va_array types, char map_to[], char buffer[],
	int flags, char flag_ch, int breadth, int accuracy, int magnitude)
{
	int i = BUFF_magnitude - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(breadth);

	num = convert_magnitude_unsgnd(num, magnitude);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_magnitude - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, breadth, accuracy, magnitude));
}
