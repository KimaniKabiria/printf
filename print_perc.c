#include "main.h"

/**
 * print_perc - printer for type %
 * @list: list
 * @buffer: write to buffer
 * @indx: the indx
 * Return: void
 */
void print_perc(
__attribute__((unused))va_list list, char *buffer, int *indx)
{
	buffer[*indx] = '%';
	*indx += 1;
}
