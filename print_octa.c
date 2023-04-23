#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_octa - printer for type o
 * @list: list
 * @buffer: buffer
 * @indx: indx
 * Return: void
 */
void print_octa(va_list list, char *buffer, int *indx)
{
	unsigned int n;
	int i;
	char *octvalues;
	char *oct;

	n = va_arg(list, int);
	octvalues = "0123456789ABCDEF";

	oct = malloc(12 * sizeof(char));
	if (oct == NULL)
		return;
	for (i = 0; n != 0; i++)
	{
		oct[i] = octvalues[n % 8];
		n /= 8;
	}
	for (i--; i >= 0; *indx += 1, i--)
	{
		buffer[*indx] = oct[i];
	}
	free(oct);

}
