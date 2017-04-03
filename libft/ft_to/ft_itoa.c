/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:41:09 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:20:28 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_itoa(int n)
{
	char			*str;
	int				neg;
	unsigned int	size[3];

	size[1] = 0;
	size[2] = 1;
	neg = (n < 0) ? 1 : 0;
	n *= (neg == 1) ? -(++size[1]) : 1;
	size[0] = n;
	while ((size[0] /= 10) > 0)
		(size[1]++);
	if ((str = (char*)malloc(sizeof(char) * (++size[1] + 1))) == NULL)
		return (NULL);
	(neg == 1) ? --size[1] : size[1];
	while ((--size[1]) > 0)
		size[2] *= 10;
	if (neg == 1)
		str[size[1]++] = '-';
	while (size[2] != 0)
	{
		(str[size[1]++] = ((n / size[2]) % 10) + 48);
		size[2] /= 10;
	}
	str[size[1]] = '\0';
	return (str);
}
