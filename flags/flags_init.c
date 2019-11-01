/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:59:06 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/26 18:16:24 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

void
	flags_init(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;
	flags->precision_upgrade = 0;
	flags->width = -1;
	flags->plus = 0;
	flags->space = 0;
	flags->sharp = 0;
	flags->quote = 0;
}
