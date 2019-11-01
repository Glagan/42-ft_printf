/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_adjust.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:27:10 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/26 17:27:31 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "transform.h"

char
	*left_adjust(char *str, int length)
{
	int	i;
	int	start;

	start = 0;
	while (str[start] == ' ')
		start++;
	i = 0;
	while (start < length)
		str[i++] = str[start++];
	while (i < length)
		str[i++] = ' ';
	return (str);
}
