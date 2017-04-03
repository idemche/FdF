/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:37:08 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:15:51 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char *p;

	p = (char *)b;
	while (len--)
		*p++ = c;
	return (b);
}
