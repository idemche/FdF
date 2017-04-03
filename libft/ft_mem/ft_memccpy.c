/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:44:50 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:15:27 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*cdst;
	char	*ssrc;

	cdst = (char *)dst;
	ssrc = (char *)src;
	while (n)
	{
		if ((*cdst++ = *ssrc++) == c)
			return (cdst);
		n--;
	}
	return (NULL);
}
