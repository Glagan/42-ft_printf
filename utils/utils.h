/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:31:33 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/27 16:52:46 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isdigit(int c);

int		is_str_format(char f);

int		ft_in_set(char c, char const *set);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(char const *s1);

size_t	ft_strlen(char const *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_strrev(char *str);

int		ft_abs(int nbr);

char	*ft_itoa(int n);

char	*ft_uitoa(unsigned int n);

#endif
