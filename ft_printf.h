/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:56:38 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/27 16:36:35 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "str/str.h"
# include "flags/flags.h"
# include "transform/transform.h"
# include "utils/utils.h"
# include "malloc_format/malloc_format.h"

# define PRINTF_VALID_FORMATS	"cspdiuxX\%"

int	ft_printf(char const *str, ...);

int	malloc_signed(char **str, int value, t_flags *flags);

int	malloc_unsigned(char **str, unsigned int value, t_flags *flags);

int	malloc_hex(char **str, char format, unsigned int val, t_flags *flags);

int	malloc_pointer(char **str, void *ptr, t_flags *flags);

int	malloc_char(char **str, int c, t_flags *flags);

int	malloc_string(char **str, char *src, t_flags *flags);

#endif
