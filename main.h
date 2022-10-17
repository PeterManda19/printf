#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_magnitude 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* magnitudeS */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct operation
 * @fmt: Format.
 * @fn: Associated function.
 */

struct fmt
{
	char fmt;
	int (*fn)(va_array, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct operation
 * @fmt: Format.
 * @fm_t: Associated function.
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_array array, char buffer[], int flags, int breadth, int accuracy, int magnitude);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int print_char(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);
int print_string(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);
int print_percent(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);

/* Functions to print numbers */
int print_int(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);
int print_binary(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);
int print_unsigned(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);
int print_octal(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);
int print_hexadecimal(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);
int print_hexa_upper(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);

int print_hexa(va_array types, char map_to[],
char buffer[], int flags, char flag_ch, int breadth, int accuracy, int magnitude);

/* Function to print non printable characters */
int print_non_printable(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);

/* Function to print memory address */
int print_pointer(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get breadth(const char *format, int *i, va_array array);
int get_accuracy(const char *format, int *i, va_array array);
int get_magnitude(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);

/*Function to print a string in rot 13*/
int print_rot13string(va_array types, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);

/* breadth Handler */
int handle_write_char(char c, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int breadth, int accuracy, int magnitude);
int write_num(int ind, char bff[], int flags, int breadth, int accuracy,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int breadth, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int breadth, int accuracy, int magnitude);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_magnitude_number(long int num, int magnitude);
long int convert_magnitude_unsgnd(unsigned long int num, int magnitude);

#endif
