#include "main.h"

/**
  * _buff_reset - function that initializes and resets a buffer
  * @buffer: buffer size
  */
void _buff_reset(char *buffer)
{
	int i;

	for (i = 0; i < 1024; i++)
	{
		buffer[i] = 0;
	}
	buffer[i] = '\0';
}

/**
 * _strlen - get length of a string
 *  @str: char pointer
 * Return: integer
 */
int _strlen(char *str)
{
	int i, length = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		length++;
	}
	return (i);
}

/**
 * _numlen - getting the length of a number
 * @num: the number
 *
 * Return: int
 */
int _numlen(int num)
{
	int n, len;

	n = num;
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
