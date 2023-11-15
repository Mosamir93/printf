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
