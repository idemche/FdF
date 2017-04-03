/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_handle_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:41:19 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:45:49 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pf_ft_handle_modifier_wc(va_list *argument, t_variables *flags)
{
	wchar_t w_char;
	wchar_t w_str[2];

	w_char = va_arg(*argument, wchar_t);
	w_str[0] = w_char;
	w_str[1] = 0;
	if (w_str[0] < 0 && w_str[0] > 55295 && w_str[0] < 57344
		&& w_str[0] > 1114111)
	{
		flags->result = -1;
		return (0);
	}
	flags->wchar_argument = w_str;
	pf_ft_handle_char(flags);
	return (0);
}

int		pf_ft_handle_c(va_list *argument, t_variables *flags)
{
	static int	mask[11] = {2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};
	char		string[2];
	char		chr;

	pf_ft_mask_initializer(flags, mask);
	if (flags->allflags.l == 1)
		return (pf_ft_handle_modifier_wc(argument, flags));
	else
	{
		chr = (char)va_arg(*argument, int);
		if (chr == 0 && flags->allflags.prec == -1)
			flags->allflags.prec = 0;
		string[0] = chr;
		string[1] = 0;
		flags->current_argument = string;
		pf_ft_handle_char(flags);
	}
	if (flags->current_argument[0] == 0)
		pf_ft_print_buffer(flags, 0);
	return (0);
}

int		pf_ft_handle_wchar(va_list *argument, t_variables *flags)
{
	static int			mask[11] = {2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};

	pf_ft_mask_initializer(flags, mask);
	return (pf_ft_handle_modifier_wc(argument, flags));
}
