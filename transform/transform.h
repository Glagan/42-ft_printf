/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:57:54 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/27 16:02:18 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "../flags/flags.h"
# include "../ft_printf.h"

char	*zero_pad_ptr(char *str, int length, int max);

char	*zero_pad(char *str, char f, int length, int max);

char	*shrink_to_empty(char *org, char f, int *length);

char	*expand_to_size(char *org, int *length, int target);

char	*left_adjust(char *str, int length);

char	*transform_value(char **str, char f,
	t_flags *flags, int *length);

#endif
