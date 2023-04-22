#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * itoa - turns a number into string.
 * @val: the value
 * @base: the base
 *
 * Return: the string
 */

char *itoa(int val, int base)
{
	static char buf[32] = {0};
	int i = 30;

	for (; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return (&buf[i + 1]);
}

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
<<<<<<< HEAD
 * Return: len
=======
 * Return: len.
>>>>>>> 6c4ac273553970a62db6968d6e59e15510820fb4
 */

int p_string(char *s)
{
if (!s)
s = "(null)";

write(1, s, strlen(s));
return (strlen(s));
}

/**
 * p_int - print int.
 * @n: the the int
 *
 * Return: the number len
 */

int p_int(int n)
{
	char *num = itoa(n, 10);

	write(1, num, strlen(num));
	return (strlen(num));
}
