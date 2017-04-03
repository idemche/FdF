/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:25:08 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:03 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	char *s;

	s = dst;
	while ((*s++ = *src++) != 0)
		;
	return (dst);
}
