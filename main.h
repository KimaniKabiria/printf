#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct type - Format Types
 *
 * @type: The format.
 * @func: The function associated.
 */
struct type
{
	char type;
	int (*func)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct type type - Format Type
 * @type: The format.
 * @types: The function associated.
 */
typedef struct type types;

int _printf(const char *format, ...);
void _print_buff(char buffer[], int *b_index);
int _printer(const char *type, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_perc(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print unknown characters */
int print_unknown(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int _getflags(const char *format, int *i);
int _width(const char *format, int *i, va_list list);
int _precision(const char *format, int *i, va_list list);
int _size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int _write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int _write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int _write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int _write_p(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int _write_u(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

int _printable(char);
int _append_hexa(char, char[], int);
int _digit(char);

long int _conv_num(long int num, int size);
long int _conv_unum(unsigned long int num, int size);

#endif
