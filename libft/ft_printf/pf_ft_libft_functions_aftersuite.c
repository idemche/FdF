/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_libft_functions_aftersuite.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:47:42 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:47:18 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pf_ft_lower_string(char *str)
{
	unsigned counter;

	counter = 0;
	if (!str)
		return (NULL);
	while (str[counter])
	{
		if (str[counter] >= 'A' && str[counter] <= 'Z')
			str[counter] += 32;
		counter++;
	}
	return (str);
}
