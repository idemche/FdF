/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:38:50 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:20:22 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int		c;
	int		num;
	int		sign;

	c = 0;
	num = 0;
	while (str[c] == ' ' || str[c] == '\t' || str[c] == '\n' || str[c] == '\v'
			|| str[c] == '\r' || str[c] == '\f')
		c++;
	sign = ((str[c] == '-') ? -1 : 1);
	if (str[c] == '-' || str[c] == '+')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		num *= 10;
		num += str[c] - '0';
		c++;
	}
	return (num * sign);
}
