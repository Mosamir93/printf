#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
#define BUFF_SIZE 1024

/**
 *struct flags - flags structure to refer to if there are any flags
 *@space: the ' ' flag
 *@hash: the # flag
 *@plus: the + flag
 *description: check if any flag is present and returns 1 or 0 if absent
 */

typedef struct flags
{
	int space;
	int hash;
	int plus;
} t_flag;

/**
 *struct spec - structure to get the specifier
 *@spec: the specifier
 *@get_fun: calls the relevent function according to the specifier
 *description: structure to determine the specifier and
 *calls the function accordingly
 */

typedef struct spec
{
	char spec;
	int (*get_fun)(va_list args, t_flag *fl);
} t_spec;

int flag_check(char p, t_flag *fl);
int parse_char(char c);
int _strlen(char *);
int pr_rev(va_list args, t_flag *fl);
int pr_int(va_list args, t_flag *);
int pr_mod(va_list args, t_flag *);
int pr_char(va_list args, t_flag *);
int pr_str(va_list args, t_flag *);
int pr_binary(va_list args, t_flag *fl);
int pr_rot13(va_list args, t_flag *fl);
int pr_shex(va_list args, t_flag *fl);
int pr_uint(va_list args, t_flag *fl);
int pr_octal(va_list args, t_flag *fl);
int pr_hex(va_list args, t_flag *fl);
int pr_chex(va_list args, t_flag *fl);
int _printf(const char *format, ...);
int (*get_spec(char p))(va_list, t_flag *);

#endif
