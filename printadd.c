#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * pr_shex - prints a string and the Non printable characters
 * (0 < ASCII value < 32 or >= 127) are printed this way: \x,
 * followed by the ASCII code value in hexadecimal (upper case - always
 * 2 characters)
 * @args: va_list to get the string from
 * @fl: flags structure
 * Return: the number of characters printed
 */
int pr_shex(va_list args, t_flag *fl)
{
	int i, count = 0;
	char *str = va_arg(args, char *);

	(void)fl;
	for (i = 0; str[i]; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			count += parse_char('\\');
			count += parse_char('x');
			count += parse_char((str[i] >> 4) < 10 ?
					('0' + (str[i] >> 4)) : ('A' + (str[i] >> 4) - 10));
			count += parse_char((str[i] & 0xF) < 10 ?
					('0' + (str[i] & 0xF)) : ('A' + (str[i] & 0xF) - 10));
		}
		else
			count += parse_char(str[i]);
	}
	return (count);
}

/**
 * pr_uint - prints unsigned int
 * @args: va_list to get the unsigned int from
 * @fl: flags structure
 * Return: number of characters printed
 */
int pr_uint(va_list args, t_flag *fl)
{
	int i, j, num;
	unsigned int x, y;
	char *s;

	x = va_arg(args, unsigned int);
	num = 0;

	if (x == 0)
	{
		num += parse_char('0');
		return (num);
	}
	if ((*fl).space && !(*fl).plus)
		num += parse_char(' ');
	if ((*fl).plus && x > 0)
		num += parse_char('+');
	y = x;

	for (i = 0; x > 0; i++)
		x /= 10;
	j = i;
	s = malloc(i * sizeof(char));
	if (s == NULL)
		return (-1);
	for (--i; i >= 0; i--)
	{
		s[i] = (y % 10) + '0';
		y /= 10;
	}
	for (i = 0; i < j; i++)
	{
		num++;
		parse_char(s[i]);
	}
	free(s);
	return (num);

}

/**
 * pr_octal - prints octal
 * @args: va_list to get int from
 * @fl: flags struct
 * Return: number of characters parsed to buffer
 */
int pr_octal(va_list args, t_flag *fl)
{
	int i, j, num;
	int x, y;
	char *s;

	x = va_arg(args, int);
	num = 0;

	if (x < 0)
		x = -x;
	if (x == 0)
	{
		num += parse_char('0');
		return (num);
	}
	if ((*fl).hash)
		num += parse_char('0');
	y = x;

	for (i = 0; x > 0; i++)
		x /= 8;
	j = i;
	s = malloc(i * sizeof(char));
	if (s == NULL)
		return (0);
	for (--i; i >= 0; i--)
	{
		s[i] = (y % 8) + '0';
		y /= 8;
	}
	for (i = 0; i < j; i++)
	{
		num++;
		parse_char(s[i]);
	}
	free(s);
	return (num);
}

/**
 * pr_chex - prints in hexadecimal form
 * @args: va_list to get int from
 * @fl: flags struct
 * Return: number of characters parsed to buffer
 */

int pr_chex(va_list args, t_flag *fl)
{
	int i, j, num;
	long int x, y;
	char *s;

	x = va_arg(args, long int);
	num = 0;

	if (x < 0)
		x = -x;
	if (x == 0)
	{
		num += parse_char('0');
		return (num);
	}
	if ((*fl).hash)
	{
		num += parse_char('0');
		num += parse_char('x');
	}
	y = x;
	for (i = 0; x > 0; i++)
		x /= 16;
	j = i;
	s = malloc(i * sizeof(char));
	if (s == NULL)
		return (0);
	for (--i; i >= 0; i--)
	{
		s[i] = ((y % 16 < 10) ? ((y % 16) + '0') : ('A' + (y % 16) - 10));
		y /= 16;
	}
	for (i = 0; i < j; i++)
	{
		num++;
		parse_char(s[i]);
	}
	free(s);
	return (num);
}

/**
 * pr_hex - prints in hexadecimal form
 * @args: va_list to get int from
 * @fl: flags struct
 * Return: number of characters parsed to buffer
 */

int pr_hex(va_list args, t_flag *fl)
{
	int i, j, num;
	long int x, y;
	char *s;

	x = va_arg(args, long int);
	num = 0;

	if (x < 0)
		x = -x;
	if (x == 0)
	{
		num += parse_char('0');
		return (num);
	}
	if ((*fl).hash)
		num += parse_char('0');
	y = x;

	for (i = 0; x > 0; i++)
		x /= 16;
	j = i;
	s = malloc(i * sizeof(char));
	if (s == NULL)
		return (0);
	for (--i; i >= 0; i--)
	{
		s[i] = ((y % 16 < 10) ? ((y % 16) + '0') : ('a' + (y % 16) - 10));
		y /= 16;
	}
	for (i = 0; i < j; i++)
	{
		num++;
		parse_char(s[i]);
	}
	free(s);
	return (num);
}
