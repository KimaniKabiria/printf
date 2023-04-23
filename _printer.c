#include "main.h"

/**
 * _printer - prints to stdout
 * @buff: what to print
 * @len: size
 * Return: 1 success.
 */

int _printer(char *buff, int len)
{
	return (write(1, buff, len));
}
