/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:41:49 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:18:19 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putnbr(int n)
{
	long num;
	long tmp;

	tmp = n;
	if (n < 0)
	{
		tmp = -tmp;
		write(1, "-", 1);
	}
	if (tmp >= 10)
		ft_putnbr(tmp / 10);
	num = tmp % 10 + 48;
	write(1, &num, 1);
}
