#include "main.h"

/**
 *get_spec - checks the specifier and returns pointer to corresponding function
 *@p: specifier to be checked
 *
 *Return: function pointer or null if not found
 */
int (*get_spec(char p))(va_list, t_flag *)
{
	int i;

	t_spec specs[] = {
		{'c', pr_char},
		{'s', pr_str},
		{'d', pr_int},
		{'i', pr_int},
		{'r', pr_rev},
		{'b', pr_binary},
		{'R', pr_rot13},
		{'S', pr_shex},
		{'u', pr_uint},
		{'o', pr_octal}
	};
	for (i = 0; i < 10; i++)
	{
		if (specs[i].spec == p)
			return (specs[i].get_fun);
	}
	return (NULL);
}

/**
 *flag_check - checks if flags are present and determines which one
 *@p: character to compare to flags
 *@fl: pointer to the t_flag structure
 *Return: 1 if flag is present 0 if not
 */

int flag_check(char p, t_flag *fl)
{
	int x = 0;

	if (p == ' ')
	{
		(*fl).space = 1;
		x = 1;
	}
	if (p == '#')
	{
		(*fl).hash = 1;
		x = 1;
	}
	if (p == '+')
	{
		(*fl).plus = 1;
		x = 1;
	}
	return (x);
}
