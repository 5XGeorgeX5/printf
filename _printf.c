#include <stdarg.h>
#include "main.h"
#include <string.h>

/**
 * _printf - print.
 * @format: the format
 *
 * Return: the number of chars
 */

int _printf(const char *format, ...)
{
	unsigned int i, len = 0;
	char *str;
	va_list args;

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
			p_char(format[i]);
		else
		{
			len--;
			i++;
			switch (format[i])
			{
				case 'c':
					p_char(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char *);
					p_string(str);
					len += strlen(str) - 1;
					break;
				case 'i':
				case 'd':
					len += p_int(va_arg(args, int)) - 1;
					break;
				case '%':
					p_char(format[i]);
					break;
				default:
					p_char('%');
					p_char(format[i]);
					len++;
					break;
			}
		}
	}
	return (len + i);
}
