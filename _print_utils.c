#include "main.h"

/**
 * _getflags - Calculates active flags
 * @format: Formatted string
 * @i: taken param.
 * Return: Flags:
 */
int _getflags(const char *format, int *i)
{
	int j, crnt;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (crnt = *i + 1; format[crnt] != '\0'; crnt++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[crnt] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = crnt - 1;

	return (flags);
}


/**
 * _width - Calculates width
 * @format: Formatted string
 * @i: no of args
 * @list: list of arguments
 * Return: width
 */

int _width(const char *format, int *i, va_list list)
{
	int crnt;
	int width = 0;

	for (crnt = *i + 1; format[crnt] != '\0'; crnt++)
	{
		if (_digit(format[crnt]))
		{
			width *= 10;
			width += format[crnt] - '0';
		}
		else if (format[crnt] == '*')
		{
			crnt++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = crnt - 1;

	return (width);
}

/**
 * _precision - Calculates precision
 * @format: Formatted string
 * @i: no of args
 * @list: args list
 * Return: Precision.
 */
int _precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}

/**
 * _size - Calculates the size to cast the argument
 * @format: Formatted
 * @i: args
 * Return: size.
 */
int _size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
