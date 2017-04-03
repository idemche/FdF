/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:05:51 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:14 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int count;

	count = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[count] == s2[count])
	{
		if (s1[count + 1] == '\0' && s2[count + 1] == '\0')
			return (1);
		count++;
	}
	return (0);
}
