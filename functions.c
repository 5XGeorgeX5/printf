#include "main.h"

/**
 * p_char - print char.
 * @c: the char
 *
 * Return: len.
 */

int p_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * p_string - print string.
 * @s: the the string
 *
 * Return: len.
 */

int p_string(char *s)
{
	return (write(1, s, strlen(s)));
}

/**
 * p_number - print number
 * @n: number to be printed
 *
 * Return: len.
 */

int p_number(int n)
{
	unsigned int n1;
	int len = 0;

	if (n < 0)
	{
		n1 = -n;
		len += p_char('-');
	}
	else
		n1 = n;

	if (n1 / 10)
		p_number(n1 / 10);

	return (p_char((n1 % 10) + '0') + len);
}

/**
 * specifier - print argument
 * @c: the specifier
 * @args: the arguments
 *
 * Return: len.
 */

int specifier(char c, va_list args)
{
	int num, len = 0;
	char *str;

	switch (c)
	{
		case 'c':
			len += p_char(va_arg(args, int));
			break;
		case 's':
			str = va_arg(args, char *);
			len += p_string(STRING);
			break;
		case 'd':
		case 'i':
			num = va_arg(args, int);
			len += p_number(num);
			break;
		case '%':
			len += p_char('%');
			break;
		default:
			len += p_char('%');
			len += p_char(c);
			break;
	}
	return (len);
}
