/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:28:55 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:50 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t len)
{
	unsigned int	it;

	if ((!(s1)) || (!(s2)))
		return (0);
	it = 0;
	while (s1[it] && it < (unsigned int)len)
	{
		if ((unsigned char)s1[it] - (unsigned char)s2[it])
			return (0);
		it++;
	}
	return ((((unsigned char)s1[it] - (unsigned char)s2[it])
				&& (it != (unsigned int)len)) ? 0 : 1);
}
