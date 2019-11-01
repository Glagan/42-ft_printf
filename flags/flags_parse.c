/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:57:58 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/26 19:51:42 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

static int
	set_width_precision(t_flags *flags, int state, char f, int value)
{
	if (value < 0 && (f == 's' || !state))
	{
		value = -value;
		flags->minus = 1;
	}
	if (!state)
		flags->width = value;
	else
		flags->precision = value;
	return (0);
}

static int
	get_precision(char const *str, int *i)
{
	int	tmp;

	tmp = 0;
	while (ft_isdigit(str[*i]))
		tmp = (tmp * 10) + (str[(*i)++] - '0');
	(*i)--;
	return (tmp);
}

t_flags
	*flags_parse(t_flags *flags, char const *str, char f, va_list *args)
{
	int	state;
	int	i;
	int	c;

	state = 0;
	i = 0;
	while ((c = ft_in_set(str[i], PRINTF_VALID_FLAGS)))
	{
		if (!state && c == '0')
			flags->zero = 1;
		else if (c == '-' && !(state = 0))
			flags->minus = 1;
		else if (c == '*')
			state = set_width_precision(flags, state, f, va_arg(*args, int));
		else if ((c >= '1' && c <= '9') || (state && (c == '0' || c == '-')))
			state = set_width_precision(flags, state, f,
						get_precision(str, &i));
		else if (c == '.' && (state = 1))
			flags->precision = 0;
		i++;
	}
	return (flags);
}
