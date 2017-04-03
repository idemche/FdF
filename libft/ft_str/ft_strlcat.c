/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:28:27 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:26 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		dlen;
	int		free_len;
	int		slen;
	char	*dend;
	int		i;

	dlen = ft_strlen(dst);
	free_len = size - dlen - 1;
	slen = ft_strlen(src);
	dend = dst + dlen;
	i = 0;
	while (i < free_len && src[i] != '\0')
	{
		dend[i] = src[i];
		i++;
	}
	dend[i] = '\0';
	return (((dlen < (int)size) ? dlen : size) + slen);
}
