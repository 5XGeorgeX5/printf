#include "main.h"

/**
 * p_bi_oc - print a binary or orctal number
 * @n: the num
 * @base: the base
 * @len: the len
 *
 * Return: len.
 */

int p_bi_oc(unsigned int n, int base, int len)
{
	unsigned int m = n;

	m /= base;
	if (m)
		len = p_bi_oc(m, base, len);
	len += p_char('0' + n % base);
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

	while (n /= 10)
		len++;

	return (len);
}
