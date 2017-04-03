/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:44:25 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:18:22 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long num;
	long tmp;

	tmp = n;
	if (n < 0)
	{
		tmp = -tmp;
		write(fd, "-", 1);
	}
	if (tmp >= 10)
		ft_putnbr_fd(tmp / 10, fd);
	num = tmp % 10 + 48;
	write(fd, &num, 1);
}
