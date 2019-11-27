/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:29:50 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/27 11:59:40 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int
	ft_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (c);
		i++;
	}
	return (0);
}

int
	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int
	is_decimal_format(char f)
{
	return (f == 'd' || f == 'i' || f == 'u'
		|| f == 'x' || f == 'X' || f == 'p');
}

int
	is_str_format(char f)
{
	return (f == 's' || f == 'c' || f == '%' || !is_decimal_format(f));
}
