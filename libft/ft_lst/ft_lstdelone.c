/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:52:24 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:15:05 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst != NULL && del != NULL)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
