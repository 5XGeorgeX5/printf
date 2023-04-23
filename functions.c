#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

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
