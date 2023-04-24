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
 */

void p_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		n1 = -n;
		p_char('-');
	}
	else
		n1 = n;

	if (n1 / 10)
		p_number(n1 / 10);

	p_char((n1 % 10) + '0');
}

/**
 * num_len - return the number len
 * @n: number to be printed
 *
 * Return: len.
 */

int num_len(int n)
{
	int len = 1;

	if (n < 0)
		len++;
	while (n /= 10)
		len++;

	return (len);
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
	unsigned int num2;
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
			p_number(num);
			len += num_len(num);
			break;
		case 'b':
			len += p_bi_oc(va_arg(args, unsigned int), 2, 0);
			break;
		case 'o'
			len += p_bi_oc(va_arg(arg, unsigned int), 8, 0);
			break;
		case 'u':
			num2 = va_arg(args, unsigned int);
			p_u_number(num2);
			len += num_u_len(num2);
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
