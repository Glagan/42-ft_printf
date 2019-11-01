/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 01:37:46 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/23 17:37:10 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int
	str_clear(t_str **lst)
{
	t_str	**init;
	t_str	*tmp;

	init = lst;
	while (lst && *lst)
	{
		if ((*lst)->content)
			free((*lst)->content);
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
	if (init)
		*init = NULL;
	return (0);
}
