/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:42:21 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/26 19:35:12 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void
	str_write(t_str *lst)
{
	if (lst && lst->length >= 0)
		write(STDOUT_FILENO, lst->content, lst->length);
}
