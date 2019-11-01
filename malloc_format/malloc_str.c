/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:18:54 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/26 19:43:01 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_format.h"

int
	malloc_char(char **str, int c, t_flags *flags)
{
	flags->org_char = c;
	if (!(*str = (char*)malloc(sizeof(*str))))
		return (-1);
	(*str)[0] = (unsigned char)c;
	return (1);
}

int
	malloc_string(char **str, char *src, t_flags *flags)
{
	int	length;

	if (!src)
		src = "(null)";
	flags->org_str = src;
	length = ft_strlen(src);
	if (!(*str = ft_strdup(src)))
		return (-1);
	return (length);
}
