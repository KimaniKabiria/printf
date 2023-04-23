#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_char - printer for type c
 * @list: list
 * @buffer: buffer
 * @indx: indx
 *
 * Return: void
 */
void print_char(va_list list, char *buffer, int *indx)
{
	char chr;

	chr = va_arg(list, int);
	if (*indx == 1024)
	{
		_printer(buffer, *indx);
		_buff_reset(buffer);
		*indx = 0;
	}
	buffer[*indx] = chr;
	*indx += 1;
}
