/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 01:36:56 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/27 17:09:58 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

t_str
	*str_add_back(t_str **alst, char *content, int length)
{
	t_str	*last;
	t_str	*new;

	if (!content || length < 0)
		return (NULL);
	if (!(new = str_new(content, length)))
	{
		free(content);
		return (NULL);
	}
	if (*alst)
	{
		last = str_last(*alst);
		last->next = new;
	}
	else
		*alst = new;
	return (new);
}
