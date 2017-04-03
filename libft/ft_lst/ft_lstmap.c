/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:54:46 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:15:12 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *one;
	t_list *two;

	one = NULL;
	if (lst != NULL)
	{
		if ((one = f(lst)) == NULL)
			return (NULL);
		two = one;
		while (lst->next != NULL)
		{
			if ((two->next = f(lst->next)) == NULL)
				return (NULL);
			two = two->next;
			lst = lst->next;
		}
	}
	return (one);
}
