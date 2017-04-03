/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:54:08 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:15:09 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		f(lst);
		lst->next = tmp;
		lst = tmp;
	}
}
