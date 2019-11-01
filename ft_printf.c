/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:56:26 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/27 17:12:01 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	format_value(char **str, char format, va_list *args, t_flags *flags)
{
	if (format == 'd' || format == 'i')
		return (malloc_signed(str, va_arg(*args, int), flags));
	else if (format == 'u')
		return (malloc_unsigned(str, va_arg(*args, unsigned int), flags));
	else if (format == 'p')
		return (malloc_pointer(str, va_arg(*args, void *), flags));
	else if (format == 'x' || format == 'X')
		return (malloc_hex(str, format, va_arg(*args, unsigned int), flags));
	else if (format == 'c')
		return (malloc_char(str, va_arg(*args, int), flags));
	else if (format == 's')
		return (malloc_string(str, va_arg(*args, char*), flags));
	return (malloc_char(str, format, flags));
}

static char
	*process_format(char *str, char f, int *length, va_list *args)
{
	char	*ret;
	t_flags	*flags;

	flags = NULL;
	ret = NULL;
	if (!str || !(flags = flags_new()))
		return (NULL);
	flags_parse(flags, str, f, args);
	free(str);
	*length = format_value(&ret, f, args, flags);
	if (!ret || *length < 0)
	{
		free(flags);
		return (NULL);
	}
	if (!transform_value(&ret, f, flags, length))
	{
		free(flags);
		return (NULL);
	}
	free(flags);
	return (ret);
}

static char
	*add_format_string(t_str **result, char const *str,
		int length, va_list *args)
{
	int		res_length;
	char	*res;

	if (!(res = process_format(
				ft_substr(str, 0, length), str[length], &res_length, args)))
		return (NULL);
	if (!str_add_back(result, res, res_length))
	{
		free(res);
		return (NULL);
	}
	return (res);
}

static int
	parse_str(char const *str, int i, t_str **result, va_list *args)
{
	int	start;

	start = i;
	while (str[i] && str[i] != '%')
		i++;
	if (i - start > 0 &&
		!str_add_back(result, ft_substr(str, start, i - start), i - start))
		return (-1);
	if (str[i] == '%' && (start = ++i) && str[i])
	{
		while (ft_in_set(str[i], PRINTF_VALID_FLAGS))
			i++;
		if (!add_format_string(result, str + start, i - start, args))
			return (-1);
		i++;
	}
	return (i);
}

int
	ft_printf(char const *str, ...)
{
	va_list	args;
	t_str	*result;
	int		i;

	if (!str)
		return (0);
	result = NULL;
	va_start(args, str);
	i = 0;
	while (str[i])
		if ((i = parse_str(str, i, &result, &args)) < 0)
		{
			va_end(args);
			return (str_clear(&result));
		}
	va_end(args);
	i = str_iter(result, &str_write);
	return (str_clear(&result) | i);
}
