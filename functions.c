#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * p_char - print char.
 * @c: the char
 *
 */

void p_char(char c)
{
	write(1, &c, 1);
}

/**
 * p_string - print string.
 * @s: the the string
 *
 */

void p_string(char *s)
{
	write(1, s, strlen(s));
}

/**
 * p_int - print int.
 * @n: the the int
 *
 * Return: the number len
 */

int p_int(int n)
{
	char num[11];

	itoa(n, num, 10);
	write(1, num, strlen(num));
	return (strlen(num));
}
