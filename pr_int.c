#include "main.h"
#include <limits.h>

/**
 *pr_int - parses an int to buffer after changing it into characters
 *@args: va_list to get the int from
 *@fl: pointer to structure to get flags from
 *Return: number of characters parsed to buffer
 */

int pr_int(va_list args, t_flag *fl)
{
	int i, j, num;
	int x, y;
	char *s;

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
		x = -x;
	}
	y = x;
	for (i = 0; x > 0; i++)
		x /= 10;
	j = i;
	s = malloc(i * sizeof(char));
	if (s == NULL)
		return (0);
	for (i -= 1; i >= 0; i--)
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
 *pr_rev - reverses string
 *@args: va_list to get string from
 *@fl: pointer to flag structure
 *Return: length of string
 */

int pr_rev(va_list args, t_flag *fl)
{
	int i;
	unsigned int num;
	char *str;

	(void)fl;
	num = 0;
	str = va_arg(args, char *);
	i = _strlen(str);

	for (i--; i >= 0; i--)
		num += parse_char(str[i]);
	return (num);
}

/**
 *_strlen - calculates sytring length
 *@s: string to get it's length
 *Return: returns length of string
 */

int _strlen(char *s)
{
	unsigned int i = 0;

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
	{	x = -x;
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

/**
 * pr_rot13 - encrypt a string using rot13
 * @args: va_list to get the string from
 * @fl: unused flag
 * Return: number of characters parsed to buffer
*/

int pr_rot13(va_list args, t_flag *fl)
{
	int i, count = 0;
	char *str = va_arg(args, char *);
	char *rot;

	rot = malloc((_strlen(str) * sizeof(char)));
	if (rot == NULL)
		return (0);
	(void)fl;
	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			rot[i] = (((str[i] - 'a' + 13) % 26) + 'a');
		else if (str[i] >= 'A' && str[i] <= 'Z')
			rot[i] = (((str[i] - 'A' + 13) % 26) + 'A');
	}
	for (i = 0; rot[i]; i++)
		count += parse_char(rot[i]);
	free(rot);
	return (count);
}
