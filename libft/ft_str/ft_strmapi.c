/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:04:50 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:36 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*str;

	if (s == NULL || f == NULL)
		return (NULL);
	count = ft_strlen(s);
	str = NULL;
	while (s[count])
		count++;
	if ((str = (char*)malloc(sizeof(char) * (count + 1))) == NULL)
		return (NULL);
	count = 0;
	while (s[count])
	{
		str[count] = (*f)(count, s[count]);
		count++;
	}
	str[count] = '\0';
	return ((char*)str);
}
