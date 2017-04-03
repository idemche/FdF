/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:43:15 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:15:38 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*ssrc;

	cdst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	while (n > 0)
	{
		*cdst++ = *ssrc++;
		n--;
	}
	return (dst);
}
