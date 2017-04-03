/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:40:52 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:18:28 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putstr(char const *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return ;
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
}
