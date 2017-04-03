/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_handle_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:46:42 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:46:22 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			pf_ft_handle_s(va_list *argument, t_variables *flags)
{
	static int	mask[11] = {2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};

	pf_ft_mask_initializer(flags, mask);
	if (flags->allflags.l == 1)
	{
		flags->wchar_argument = va_arg(*argument, wchar_t*);
		pf_ft_handle_char(flags);
		return (0);
	}
	else
		flags->current_argument = va_arg(*argument, char*);
	if (flags->current_argument == 0)
		flags->current_argument = "(null)";
	pf_ft_handle_char(flags);
	return (0);
}

int			pf_ft_handle_wchar_s(va_list *argument, t_variables *flags)
{
	static int	mask[11] = {2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};

	pf_ft_mask_initializer(flags, mask);
	flags->wchar_argument = va_arg(*argument, wchar_t*);
	pf_ft_handle_char(flags);
	return (0);
}
