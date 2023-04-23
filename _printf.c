#include "main.h"

/**
 * _printf - Main Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_c = 0;
	int flags, width, precision, size, b_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[b_index++] = format[i];
			if (b_index == BUFF_SIZE)
				_print_buff(buffer, &b_index);
			printed_c++;
		}
		else
		{
			_print_buff(buffer, &b_index);
			flags = _getflags(format, &i);
			width = _width(format, &i, list);
			precision = _precision(format, &i, list);
			size = _size(format, &i);
			++i;
			printed = _printer(format, &i, list, buffer,
					       flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_c += printed;
		}
	}
	_print_buff(buffer, &b_index);
	va_end(list);
	return (printed_c);
}
