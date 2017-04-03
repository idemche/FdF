/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:36:53 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:43 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	i;
	unsigned char	*u1;
	unsigned char	*u2;

	i = 0;
	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (i < n)
	{
		if (u1[i] != u2[i])
			return (u1[i] - u2[i]);
		else if (u1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
