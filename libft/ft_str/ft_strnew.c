/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:49:49 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:19:54 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	counter;

	counter = 0;
	str = NULL;
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while ((size-- + 1) != 0)
		str[counter++] = '\0';
	return (str);
}
