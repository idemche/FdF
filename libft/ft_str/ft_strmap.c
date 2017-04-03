/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:04:11 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:33 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		count;
	char	*str;

	if (s && f)
	{
		count = 0;
		str = NULL;
		count = ft_strlen(s);
		if ((str = (char*)malloc(sizeof(char) * (count + 1))) == NULL)
			return (NULL);
		count = 0;
		while (s[count])
		{
			str[count] = (*f)(s[count]);
			count++;
		}
		str[count] = '\0';
		return ((char*)str);
	}
	return (NULL);
}
