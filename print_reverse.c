#include "main.h"
/**
 * print_reverse - funtion for reversed string
 * @list: argument passed in
 * @buffer: values stored
 * @indx: returns pointer to indx
 */
void print_reverse(va_list list, char *buffer, int *indx)
{
	int i, strlen;
	char *s;

	s = va_arg(list, char *);
	strlen = _strlen(s) - 1;

	for (i = strlen; i >= 0; i--, *indx += 1)
	{
		buffer[*indx] = s[i];
	}
}
