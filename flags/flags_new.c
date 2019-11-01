/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:47:38 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/26 17:42:17 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

t_flags
	*flags_new(void)
{
	t_flags	*new;

	if (!(new = (t_flags*)malloc(sizeof(*new))))
		return (NULL);
	flags_init(new);
	return (new);
}
