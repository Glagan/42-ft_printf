/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 01:35:47 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/23 17:37:30 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

t_str
	*str_new(void *content, int length)
{
	t_str	*elt;

	elt = (t_str*)malloc(sizeof(*elt));
	if (!elt)
		return (NULL);
	elt->length = length;
	elt->content = content;
	elt->next = NULL;
	return (elt);
}
