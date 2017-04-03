/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:24:47 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:57 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	one;
	unsigned int	two;
	int				found;

	one = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[one] && one < len)
	{
		if (big[one] == little[0])
		{
			two = 0;
			found = 1;
			while (little[two] && found)
			{
				if (big[one + two] != little[two])
					found = 0;
				two++;
			}
			if (found && (one + two) <= len)
				return ((char *)big + one);
		}
		one++;
	}
	return (0);
}
