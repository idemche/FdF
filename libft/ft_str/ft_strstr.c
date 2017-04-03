/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:32:05 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:20:10 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		c;
	int		cc;
	int		found;

	c = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[c])
	{
		if (big[c] == little[0])
		{
			cc = 0;
			found = 1;
			while (little[cc] && found)
			{
				if (big[c + cc] != little[cc])
					found = 0;
				cc++;
			}
			if (found)
				return ((char *)big + c);
		}
		c++;
	}
	return (0);
}
