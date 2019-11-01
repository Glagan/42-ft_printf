/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 01:42:11 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/23 17:45:07 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int
	str_iter(t_str *lst, void (*f)(t_str*))
{
	int	total;

	total = 0;
	if (!f)
		return (0);
	while (lst)
	{
		(*f)(lst);
		total += lst->length;
		lst = lst->next;
	}
	return (total);
}
