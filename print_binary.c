#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_binary - printer for binary type
 * @list: taking in arguments
 * @buffer: values stored
 * @indx: tracks the indx position
 */
void print_binary(va_list list, char *buffer, int *indx)
{
	unsigned int n;
	int i;
	char *binaryvalues;
	char *binary;

	n = va_arg(list, int);
	binaryvalues = "01";
	binary = malloc(33 * sizeof(char));
	if (binary == NULL)
		return;
	if (n == 0)
	{
		buffer[*indx] = '0';
		*indx += 1;
	}
	else
	{
		for (i = 0; n != 0; i++)
		{
			binary[i] = binaryvalues[n % 2];
			n /= 2;
		}
		for (i--; i >= 0; *indx += 1, i--)
		{
			buffer[*indx] = binary[i];
		}
	}
	free(binary);
}
