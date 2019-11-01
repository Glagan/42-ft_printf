/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_pad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:25:33 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/26 17:43:50 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

char
	*zero_pad_ptr(char *str, int length, int max)
{
	int	i;
	int	min;

	min = length - max;
	i = 0;
	while (str[i] != 'x')
	{
		if (i >= min)
			str[i] = '0';
		i++;
	}
	if (i >= min)
	{
		str[i] = '0';
		str[1] = 'x';
	}
	return (str);
}

char
	*zero_pad(char *str, char f, int length, int max)
{
	int	i;
	int	is_neg_int;
	int	min;

	if (f == 'p')
		return (zero_pad_ptr(str, length, max));
	is_neg_int = 0;
	min = length - max;
	i = 0;
	while (i < length
		&& ((str[i] == ' ')
		|| (f == 'd' && str[i] == '-' && (is_neg_int = 1))))
	{
		if (i >= min)
			str[i] = '0';
		i++;
	}
	if (is_neg_int)
	{
		i = 0;
		while (str[i] == ' ')
			i++;
		str[i] = '-';
	}
	return (str);
}
