#include "main.h"

/**
 *pr_int - parses an int to buffer after changing it into characters
 *@args: va_list to get the int from
 *@fl: pointer to structure to get flags from
 *Return: number of characters parsed to buffer
 */

int pr_int(va_list args, t_flag *fl)
{
	int i, num, x, y;
	char s[20] = {0};

	x = va_arg(args, int);
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
	if (x < 0)
	{
		num += parse_char('-');
		x = (-1) * x;
	}
	y = x;
	for (i = 0; x > 0; i++)
		x /= 10;
	for (i -= 1; i >= 0; i--)
	{
		s[i] = (y % 10) + '0';
		y /= 10;
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		num += parse_char(s[i]);
	}
	return (num);

}

/**
 *pr_rev - reverses string
 *@args: va_list to get string from
 *@fl: pointer to flag structure
 *Return: length of string
 */

int pr_rev(va_list args, t_flag *fl)
{
	int i, j, num;
	char *s;
	char temp;

	(void)fl;
	num = 0;
	s = va_arg(args, char *);
	i = _strlen(s);

	for (j = i - 1; j >= i / 2; j--)
	{
		temp = s[j];
		s[j] = s[(i - 1) - j];
		s[(i - 1) - j] = temp;
	}
	for (j = 0; s[j]; j++)
		num += parse_char(s[j]);
	return (num);
}

/**
 *_strlen - calculates sytring length
 *@s: string to get it's length
 *Return: returns length of string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
