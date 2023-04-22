#include <stdarg.h>
#include "main.h"
#include <string.h>

#define STRING ((str) ? str : "(null)")

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
	{
			len += p_char(format[i]);
			continue;
		}
		switch (format[i])
		{
			case 'c':
				len += p_char(va_arg(args, int));
				break;
			case 's':
				str = va_arg(args, char *);
				len += p_string(STRING);
				break;
			case '%':
				len += p_char(format[i]);
				break;
			default:
				len += p_char('%');
				len += p_char(format[i]);
				break;
		}
	}
	va_end(args);
	return (len);
}
