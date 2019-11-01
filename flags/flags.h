/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:46:27 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/27 16:37:00 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include <stdlib.h>
# include <stdarg.h>
# include "../utils/utils.h"

# define PRINTF_VALID_FLAGS 	"-.*0123456789"

# define FLAG_ZERO		0
# define FLAG_MINUS		1
# define FLAG_WIDTH		2
# define FLAG_PRECISION	3
# define FLAG_PLUS		4
# define FLAG_SPACE		5
# define FLAG_SHARP		6
# define FLAG_QUOTE		7

typedef struct	s_flags
{
	int				zero;
	int				minus;
	int				width;
	int				precision;
	int				precision_upgrade;

	int				org_signed;
	unsigned int	org_unsigned;
	void			*org_ptr;
	char			org_char;
	char			*org_str;

	int				plus;
	int				space;
	int				sharp;
	int				quote;
}				t_flags;

void			flags_init(t_flags *flags);

t_flags			*flags_new(void);

t_flags			*flags_parse(t_flags *flags, char const *str,
					char f, va_list *args);

#endif
