/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:22:40 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/27 12:07:16 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

static int
	value_is_0(t_flags *flags, char f)
{
	return (((f != 'd' && f != 'i') || !flags->org_signed)
		&& (f != 'p' || !(long)flags->org_ptr)
		&& ((f != 'u' && f != 'x' && f != 'X') || !flags->org_unsigned));
}

static void
	adjust_pad_prec(t_flags *flags, char *str, char f, int *length)
{
	if (flags->minus)
		left_adjust(str, *length);
	else if (flags->zero)
		zero_pad(str, f, *length,
			(flags->precision >= 0 && flags->precision_upgrade)
			? flags->precision : *length);
}

static void
	adjust_pad(t_flags *flags, char *str, char f, int *length)
{
	if (flags->minus)
		left_adjust(str, *length);
	else if (flags->zero && f != 'c')
		zero_pad(str, f, *length,
			(flags->precision >= 0)
			? flags->precision : *length);
}

static char
	*expand_if_required(char **str, t_flags *flags, char f, int *length)
{
	flags->precision_upgrade = 1;
	if (flags->precision >= *length &&
		!(*str = expand_to_size(*str, length, flags->precision
			+ (f == 'd' && flags->org_signed < 0)
			+ (f == 'p' ? 2 : 0))))
		return (NULL);
	return (*str);
}

char
	*transform_value(char **org, char f, t_flags *flags, int *length)
{
	char	*str;

	str = *org;
	if (flags->precision == 0 && !is_str_format(f) && value_is_0(flags, f)
		&& !(str = shrink_to_empty(str, f, length)))
		return (NULL);
	else if (f == 's' && flags->precision >= 0 && flags->precision < *length)
		*length = flags->precision;
	else if (!is_str_format(f) && flags->precision >= 0
			&& ft_in_set(f, PRINTF_VALID_FORMATS))
	{
		if (!expand_if_required(&str, flags, f, length))
			return (NULL);
		zero_pad(str, f, *length, *length);
	}
	if (flags->width > 0 && (*length) < flags->width)
	{
		if (!(str = expand_to_size(str, length, flags->width)))
			return (NULL);
		adjust_pad_prec(flags, str, f, length);
	}
	if (flags->width < 0 && flags->precision < 0)
		adjust_pad(flags, str, f, length);
	*org = str;
	return (str);
}
