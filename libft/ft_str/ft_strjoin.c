/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:30:53 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/15 18:02:49 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	int		cc;
	char	*str;

	c = 0;
	cc = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[c++])
		;
	while (s2[cc++])
		;
	if ((str = (char*)malloc(sizeof(str) * (c + cc + 1))) == NULL)
		return (NULL);
	c = -1;
	while (s1[++c])
		str[c] = s1[c];
	cc = 0;
	while (s2[cc])
		str[c++] = s2[cc++];
	str[c] = '\0';
	return (str);
}
