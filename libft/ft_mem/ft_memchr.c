/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:57:26 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:15:30 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	u;
	unsigned char	i;

	p = (unsigned char *)s;
	u = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(p + i) == u)
			return (p + i);
		i++;
	}
	return (0);
}
