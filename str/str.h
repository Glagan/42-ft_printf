/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 01:39:22 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/26 19:35:03 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_str
{
	int				length;
	char			*content;
	struct s_str	*next;
}				t_str;

t_str			*str_last(t_str *lst);

t_str			*str_new(void *content, int length);

t_str			*str_add_back(t_str **alst, char *content, int length);

int				str_clear(t_str **lst);

int				str_iter(t_str *lst, void (*f)(t_str*));

void			str_write(t_str *lst);

#endif
