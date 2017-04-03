/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:43:13 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:18:32 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putstr_fd(char const *s, int fd)
{
	int	count;

	count = 0;
	if (s == NULL)
		return ;
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
}
