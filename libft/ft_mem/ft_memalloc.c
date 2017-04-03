/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:48:23 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:15:23 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memalloc(size_t size)
{
	void *str;

	if ((str = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
