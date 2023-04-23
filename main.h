#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct types - struct
 * @type: identifier of type
 * @function: functions that print by type
 */
typedef struct types
{
	char type;
	void (*function)();
} _type;

int _printf(const char *format, ...);

/* Common Functions */
int _printer(char *buff, int len);
int _strlen(char *s);
void _buff_reset(char *buffer);
int _numlen(int num);
char *itos(char str[], long int n);

void print_char(va_list valist, char *buffer, int *index);
void print_str(va_list list, char *buffer, int *index);
void print_perc(va_list valist, char *buffer, int *index);
void print_decimal(va_list list, char *buffer, int *indx);

#endif
