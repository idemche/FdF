/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:52:43 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:14:59 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *next;

	list = (*alst)->next;
	while (list != NULL)
	{
		next = list->next;
		del(list->content, list->content_size);
		free(list);
		list = next;
	}
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
