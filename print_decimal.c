#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * itos - integer to string
 * @str: char array
 * @n: number
 * Return: char array
 */
char *itos(char str[], long int n)
{
	int i, temp, div, length, last;

	last = n % 10;
	i = 0;
	if (last < 0)
	{
		last *= -1;
		str[i] = '-';
		i++;
	}
	n = (n / 10);
	if (n < 0)
	{
		n *= -1;
	}

	length = 0;
	div = 1;
	temp = n;

	while (temp > 0)
	{
		length += 1;
		div *= 10;
		temp = temp / 10;
	}

	div = div / 10;
	while (div >= 1)
	{
		str[i] = ((n / div) + '0');
		n = n % div;
		div /= 10;
		i++;
	}
	str[i] = last + '0';
	return (str);
}

/**
 * utos - uint to string
 * @str: string
 * @num: num
 *
 * Return: char array
 */
char *utos(char str[], unsigned int num)
{
	int i, rem, len = 0, n;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	i = 0;

	while (i < len)
	{
		rem = num % 10;
		num = num / 10;

		str[len - (i + 1)] = rem + '0';
		i++;
	}

	str[len] = '\0';
	return (str);
}

/**
 * print_decimal - printer for type d
 * @list: arguments passed
 * @buffer: values stored
 * @indx: tracks position
 */
void print_decimal(va_list list, char *buffer, int *indx)
{
	int i, j, len;
	char *str;

	i = va_arg(list, int);

	len = _numlen(i);
	if (i < 0)
	{
		len += 1;
	}
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return;
	itos(str, i);
	for (i = *indx, j = 0; j < len; *indx += 1, i++, j++)
	{
		if (*indx == 1024)
		{
			_printer(buffer, *indx);
			_buff_reset(buffer);
			*indx = 0;
		}
		buffer[*indx] = str[j];
	}
	free(str);
}


/**
 * print_udecimal - printer for type u
 * @list: list
 * @buffer: buffer
 * @indx: indx
 * Return: void
 */
void print_udecimal(va_list list, char *buffer, int *indx)
{
	unsigned int i;
	int j, numlen;
	char *num_str;

	i = va_arg(list, int);
	numlen = _numlen(i);
	num_str = malloc(numlen * sizeof(char));
	if (num_str == NULL)
		return;
	utos(num_str, i);
	for (i = *indx, j = 0; j < numlen; *indx += 1, i++, j++)
	{
		if (*indx == 1024)
		{
			_printer(buffer, *indx);
			_buff_reset(buffer);
			*indx = 0;
		}
		buffer[*indx] = num_str[j];
	}
	free(num_str);
}
