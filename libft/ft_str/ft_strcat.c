/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:26:43 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:18:36 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(s1);
	src_len = ft_strlen(s2);
	ft_memcpy(s1 + dest_len, s2, src_len + 1);
	return (s1);
}
