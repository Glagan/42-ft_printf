/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrink_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:25:31 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/26 19:45:53 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

char
	*shrink_to_empty(char *org, char f, int *length)
{
	char	*str;

	free(org);
	if (f == 'p')
	{
		if (!(str = (char*)malloc(sizeof(*str) * 2)))
			return (NULL);
		str[0] = '0';
		str[1] = 'x';
		*length = 2;
	}
	else
	{
		if (!(str = (char*)malloc(sizeof(*str))))
			return (NULL);
		str[0] = 0;
		*length = 0;
	}
	return (str);
}

char
	*expand_to_size(char *org, int *length, int target)
{
	char	*str;
	int		i;
	int		j;

	str = NULL;
	if ((str = (char*)malloc(sizeof(*str) * target)))
	{
		ft_bzero(str, target);
		i = 0;
		while (i < (target - (*length)))
			str[i++] = ' ';
		j = 0;
		while (i < target)
			str[i++] = org[j++];
	}
	*length = target;
	free(org);
	return (str);
}
