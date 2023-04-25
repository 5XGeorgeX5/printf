#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define STRING ((str) ? str : "(null)")

int _printf(const char *format, ...);
int p_char(char c);
int p_string(char *s);
void p_number(int n);
int num_len(int n);
int specifier(char c, va_list args);
int p_base(unsigned int n, int base, int cap, int len);
void p_u_number(unsigned int n);
int num_u_len(unsigned int n);
int p_s_string(char *s);
int p_address(unsigned long n, int len);
int h_address(unsigned long p);

#endif
