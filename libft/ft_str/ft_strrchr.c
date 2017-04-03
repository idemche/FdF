/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:30:10 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:20:01 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		end;
	char	ch;
	char	*ret;

	end = 0;
	ch = c;
	ret = NULL;
	while (1)
	{
		if (*s == ch)
			ret = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (ret);
}
