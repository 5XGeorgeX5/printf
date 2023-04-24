#include "main.h"

/**
 * p_base - print a number
 * @n: the num
 * @base: the base
 * @len: the len
 * @cap: the capitalization
 *
 * Return: len.
 */

int p_base(unsigned int n, int base, int cap, int len)
{
	unsigned int m = n;

	m /= base;
	if (m)
		len = p_base(m, base, cap, len);
	if (n % base < 10)
		len += p_char('0' + n % base);
	else
		len += p_char(cap + n % base);
	return (len);
}

/**
 * p_u_number - print unsigned number
 * @n: number to be printed
 *
 */

void p_u_number(unsigned int n)
{
	if (n / 10)
		p_number(n / 10);

	p_char((n % 10) + '0');
}

/**
 * num_u_len - return the number len
 * @n: number to be printed
 *
 * Return: len.
 */

int num_u_len(unsigned int n)
{
	int len = 1;

	p_u_number(n);
	while (n /= 10)
		len++;

	return (len);
}

/**
 * p_s_string - print string
 * @s: number to be printed
 *
 * Return: len.
 */

int p_s_string(char *s)
{
	int i, len = 0;

	for (i = 0; i < (int)strlen(s); i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			len += p_char('\\');
			len += p_char('x');
			if (s[i] < 16)
				len += p_char('0');
			len += p_base(s[i], 16, 55, 0);
		}
		else
			len += p_char(s[i]);
	}
	return (len);
}
