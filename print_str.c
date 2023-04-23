#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_str - ptinter for type s
 * @list: list
 * @buffer: buffer
 * @indx: indx
 * Return: void
 */
void print_str(va_list list, char *buffer, int *indx)
{
	int i, j;
	char *s;

	s = va_arg(list, char*);
	if (s == NULL)
		s = "(null)";
	for (i = *indx, j = 0; s[j] != '\0';  *indx += 1, i++, j++)
	{
		if (*indx == 1024)
		{
			_printer(buffer, indx);
			_buff_reset(buffer);
			*indx = 0;
		}
		buffer[*indx] = s[j];
	}
}
