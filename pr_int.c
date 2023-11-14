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

	x = va_arg(args, long int);
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
	int i, num;
	char *s;

	(void)fl;
	num = 0;
	s = va_arg(args, char *);
	i = _strlen(s);

	for (; i >= 0; i--)
		num += parse_char(s[i]);
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

	while (s[i])
		i++;
	return (i);
}

/**
 * pr_binary - prints binary of an unsigned int
 * @args: va_list to get the unsigned int from
 * @fl: unused flag argument
 * Return: number of elements parsed to the buffer
*/
int pr_binary(va_list args, t_flag *fl)
{
	long int x = va_arg(args, long int);
	int i, count = 0, index = 0;
	int binary[64];

	(void)fl;

	if (x == 0)
	{
		parse_char('0');
		return (1);
	}
	if (x < 0)
	{	x = -x
		count += parse_char('1');
	}
	while (x > 0)
	{	binary[index++] = x % 2;
		x /= 2;
	}
	for (i = index - 1; i >= 0; i--)
		parse_char(binary[i] + '0');
	return (count + index);
}
