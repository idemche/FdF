/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:01:25 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:15:34 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char ch1;
	unsigned char ch2;

	while (n--)
	{
		ch1 = *(unsigned char *)s1;
		ch2 = *(unsigned char *)s2;
		if (ch1 != ch2)
			return (ch1 - ch2);
		s1++;
		s2++;
	}
	return (0);
}
