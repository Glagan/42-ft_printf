/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_format.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:18:21 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/26 19:43:09 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_FORMAT_H
# define MALLOC_FORMAT_H

# define HEXADECIMAL_FORMAT(m)	((!m) ? "0123456789abcdef" : "0123456789ABCDEF")

# include "../flags/flags.h"

int	malloc_signed(char **str, int value, t_flags *flags);

int	malloc_unsigned(char **str, unsigned int value, t_flags *flags);

int	malloc_hex(char **str, char format, unsigned int val, t_flags *flags);

int	malloc_pointer(char **str, void *ptr, t_flags *flags);

int	malloc_char(char **str, int c, t_flags *flags);

int	malloc_string(char **str, char *src, t_flags *flags);

#endif
