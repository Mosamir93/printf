#include "main.h"
#include <stdarg.h>

int parse_char(char c);

/**
 *pr_char - parses character to buffer
 *@args: va_list to get the character from
 *@fl: pointer to flag structure
 *Return: 1 which stands for one character
 */

int pr_char(va_list args, t_flag *fl)
{
	(void)fl;
	parse_char(va_arg(args, int));
	return (1);
}

/**
 *pr_str - parses string to buffer and adds null character after it
 *@args: va_list to get string from
 *@fl: pointer to t_flag structure
 *Return: string length parsed to buffer
 */

int pr_str(va_list args, t_flag *fl)
{
	int i, x;
	char *str;
	(void)fl;

	i = x = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		x += parse_char(str[i]);
		i++;
	}
	return (x);
}

/**
 *parse_char - parses characters to buffer and prints them if buffer is full
 *or if -1 is passed to it
 *@c: the character passed
 *Return: 1 if parsed or written succefully -1 if not
 */

int parse_char(char c)
{
	static int i;
	static char buffer[BUFF_SIZE];

	if (i >= BUFF_SIZE || c == -1)
	{
		write(1, buffer, i);
		i = 0;
	}
	else
		buffer[i++] = c;
	return (1);
}

/**
 *_printf - custom made printf function
 *@format: format string to get specifiers from
 *Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	static int count;
	const char *p = format;
	va_list args;
	int (*spec_func)(va_list, t_flag *);
	t_flag flag = {0, 0, 0};

	va_start(args, format);
	count = 0;
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (; *p; p++)
	{
		if (*p != '%')
			count += parse_char(*p);
		else if (*p == '%')
		{
			++p;
			if (*p == '%')
			{
				count += parse_char(*p);
				continue;
			}
			for (; flag_check(*p, &flag); p++)
				;
			spec_func = get_spec(*p);
			if (spec_func)
				count += spec_func(args, &flag);
			else
				_printf("%%%c", *p);
		}
	}
	va_end(args);
	parse_char(-1);
	return (count);
}
