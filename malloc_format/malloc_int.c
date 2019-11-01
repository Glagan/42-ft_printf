/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:54:03 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/26 18:22:45 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_format.h"

int
	malloc_signed(char **str, int value, t_flags *flags)
{
	int	length;
	int	tmp;

	flags->org_signed = value;
	length = 1 + (value < 0);
	tmp = value;
	while ((tmp >= 10 || tmp <= -10) && length++)
		tmp /= 10;
	if (!(*str = ft_itoa(value)))
		return (-1);
	return (length);
}

int
	malloc_unsigned(char **str, unsigned int value, t_flags *flags)
{
	int				length;
	unsigned int	tmp;

	flags->org_unsigned = value;
	length = 1;
	tmp = value;
	while (tmp >= 10 && length++)
		tmp /= 10;
	if (!(*str = ft_uitoa(value)))
		return (-1);
	return (length);
}

int
	malloc_hex(char **str, char format, unsigned int val, t_flags *flags)
{
	size_t			i;
	int				length;
	const int		maj = (format == 'X');
	unsigned int	tmp;

	flags->org_unsigned = val;
	length = 1;
	tmp = val;
	while (tmp > 15 && length++)
		tmp /= 16;
	if (!(*str = (char*)malloc(length * sizeof(char*))))
		return (-1);
	ft_bzero(*str, length);
	if (val == 0)
		(*str)[0] = '0';
	i = length - 1;
	while (val > 0)
	{
		(*str)[i--] = HEXADECIMAL_FORMAT(maj)[val % 16];
		val = val / 16;
	}
	return (length);
}

int
	malloc_pointer(char **str, void *ptr, t_flags *flags)
{
	size_t			i;
	int				length;
	long unsigned	tmp;

	flags->org_ptr = ptr;
	length = 3;
	tmp = (long)ptr;
	while (tmp > 15 && length++)
		tmp /= 16;
	if (!(*str = (char*)malloc(length * sizeof(char*))))
		return (-1);
	ft_bzero(*str, length);
	(*str)[0] = '0';
	(*str)[1] = 'x';
	tmp = (long)ptr;
	if (tmp == 0)
		(*str)[2] = '0';
	i = length - 1;
	while (tmp > 0)
	{
		(*str)[i--] = HEXADECIMAL_FORMAT(0)[tmp % 16];
		tmp = tmp / 16;
	}
	return (length);
}
