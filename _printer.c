#include "main.h"
/**
 * _printer - Prints based on type
 * @format: Formatted string
 * @list: args list
 * @index: index
 * @buffer: Buffer array
 * @flags: active flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: 1 or 2;
 */
int _printer(const char *format, int *index, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, u_len = 0, printed_chars = -1;
	types typ[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_perc},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_unknown},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; typ[i].type != '\0'; i++)
		if (format[*index] == typ[i].type)
			return (typ[i].func(list, buffer, flags, width, precision, size));

	if (typ[i].type == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		u_len += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			u_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		u_len += write(1, &format[*index], 1);
		return (u_len);
	}
	return (printed_chars);
}

/**
 * _print_buff - Prints the buffer
 * @buffer: Array of chars
 * @b_indexex: buffer indexex.
 */
void _print_buff(char buffer[], int *b_indexex)
{
	if (*b_indexex > 0)
		write(1, &buffer[0], *b_indexex);

	*b_indexex = 0;
}

/**
 * _printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int _printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
