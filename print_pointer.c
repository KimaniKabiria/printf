#include "main.h"
#include <stdlib.h>
/**
 * print_pointer - printer for pointer address
 * @list: argument list
 * @buffer: values stored
 * @indx: tracks the indx position
 */
void print_pointer(va_list list, char *buffer, int *indx)
{
	print_lx(list, buffer, indx);
}

/**
 * print_lx - printer for long address
 * @list: argument list
 * @buffer: values stored
 * @indx: tracks the indx position
 */
void print_lx(va_list list, char *buffer, int *indx)
{
	unsigned long int n;
	int i;
	char *hexvalues;
	char *hex;
	void *a;
	char *b;

	a = va_arg(list, void *);
	b = "(nil)";
	if (a == NULL)
		for (i = 0; i < 5; i++, *indx += 1)
			buffer[*indx] = b[i];
	n = (unsigned long int)a;
	hexvalues = "0123456789abcdef";
	hex = malloc(14 * sizeof(char));

	for (i = 0; n != 0; i++)
	{
		hex[i] = hexvalues[n % 16];
		n /= 16;
	}
	i += 2;
	hex[13] = '0';
	hex[12] = 'x';
	for (i--; i >= 0; *indx += 1, i--)
	{
		buffer[*indx] = hex[i];
	}
}
