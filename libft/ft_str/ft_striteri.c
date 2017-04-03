/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:02:47 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:20 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	counter;

	if (s == NULL || f == NULL)
		return ;
	counter = 0;
	while (s[counter])
	{
		f(counter, s + counter);
		counter++;
	}
}
