#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_hexa - printer for type h
 * @list: list
 * @buffer: buffer
 * @indx: indx
 * Return: void
 */
void print_hexa(va_list list, char *buffer, int *indx)
{
	unsigned int n;
	int i;
	char *hexvalues;
	char *hex;

	n = va_arg(list, int);
	hexvalues = "0123456789abcdef";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return;
	for (i = 0; n != 0; i++)
	{
		hex[i] = hexvalues[n % 16];
		n /= 16;
	}
	for (i--; i >= 0; *indx += 1, i--)
	{
		buffer[*indx] = hex[i];
	}
	free(hex);
}

/**
 * print_chexa - printer for type ch
 * @list: list
 * @buffer: buffer
 * @indx: indx
 * Return: void
 */
void print_chexa(va_list list, char *buffer, int *indx)
{
	unsigned int n;
	int i;
	char *hexvalues;
	char *hex;

	n = va_arg(list, int);
	hexvalues = "0123456789ABCDEF";
	hex = malloc(9 * sizeof(char));
	if (hex == NULL)
		return;
	for (i = 0; n != 0; i++)
	{
		hex[i] = hexvalues[n % 16];
		n /= 16;
	}
	for (i--; i >= 0; *indx += 1, i--)
	{
		buffer[*indx] = hex[i];
	}
	free(hex);
}
