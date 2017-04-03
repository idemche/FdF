/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:37:09 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:20:17 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strtrim(char const *s)
{
	int		c;
	int		cc;
	int		dif;
	int		count;
	char	*str;

	c = 0;
	cc = 0;
	count = 0;
	if (s == NULL)
		return (NULL);
	cc = ft_strlen(s);
	while (s[c] == ' ' || s[c] == '\t' || s[c] == '\n')
		if (s[c++ + 1] == '\0')
			return ("\0");
	while ((s[--cc] == ' ' || s[cc] == '\t' || s[cc] == '\n') && cc != '\0')
		;
	dif = ++cc - c;
	if ((str = (char*)malloc(sizeof(char) * (dif + 1))) == NULL)
		return (NULL);
	while (0 < dif--)
		str[count++] = s[c++];
	str[count] = '\0';
	return (str);
}
