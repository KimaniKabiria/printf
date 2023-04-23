#include "main.h"
/**
  * _printf - function that prints based on format specifier
  * @format: takes in format specifier
  * Return: return pointer to indx
  */
int _printf(const char *format, ...)
{
	char buffer[1024];
	int i, j = 0, x = 0, *indx = &x;
	va_list list;
	_type type[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_perc},
		{'d', print_decimal}, {'i', print_decimal},
		{'\0', NULL}
	};

	if (!format)
		return (-1);
	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		for (; format[i] != '%' && format[i] != '\0'; *indx += 1, i++)
		{
			if (*indx == 1024)
			{	_printer(buffer, indx);
				_buff_reset(buffer);
				*indx = 0;
			}
			buffer[*indx] = format[i];
		}
		if (format[i] == '\0')
			break;
		if (format[i] == '%')
		{	i++;
			for (j = 0; type[j].type != '\0'; j++)
			{
				if (format[i] == type[j].type)
				{	type[j].function(list, buffer, indx);
					break;
				}
			}
		}
	}
	va_end(list);
	buffer[*indx] = '\0';
	_printer(buffer, indx);
	return (*indx);
}
