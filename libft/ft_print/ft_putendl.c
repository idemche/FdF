/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:41:22 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:17:56 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putendl(char const *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return ;
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	write(1, "\n", 1);
}
