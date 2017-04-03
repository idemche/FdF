/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:25:31 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:46 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *s;

	s = dst;
	while (len > 0 && *src != 0)
	{
		*s++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*s++ = 0;
		len--;
	}
	return (dst);
}
