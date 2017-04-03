/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_handle_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:41:20 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:45:59 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pf_ft_handle_modifier_d(va_list *argument, t_variables *flags)
{
	uintmax_t	full_return_value;
	intmax_t	return_value;

	return_value = 0;
	if (flags->allflags.z == 1)
		return_value = (intmax_t)(va_arg(*argument, ssize_t));
	else if (flags->allflags.j == 1)
		return_value = (va_arg(*argument, intmax_t));
	else if (flags->allflags.ll == 1)
		return_value = (intmax_t)(va_arg(*argument, long long));
	else if (flags->allflags.l == 1)
		return_value = (intmax_t)(va_arg(*argument, long));
	else if (flags->allflags.h == 1)
		return_value = (intmax_t)((short)va_arg(*argument, int));
	else if (flags->allflags.hh == 1)
		return_value = (intmax_t)((char)va_arg(*argument, int));
	else if (flags->specifier == 'D')
		return_value = (intmax_t)(va_arg(*argument, long));
	else if (flags->specifier == 'd' || flags->specifier == 'i')
		return_value = (intmax_t)(va_arg(*argument, int));
	full_return_value = pf_ft_sign_flag(flags, return_value);
	return (pf_ft_itoa_base(full_return_value, 10));
}

int		pf_ft_handle_d(va_list *argument, t_variables *flags)
{
	static int	mask[11] = {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	pf_ft_mask_initializer(flags, mask);
	flags->current_argument = pf_ft_handle_modifier_d(argument, flags);
	pf_ft_handle_numbers(flags);
	return (0);
}

int		pf_ft_handle_wchar_d(va_list *argument, t_variables *flags)
{
	static int	mask[11] = {2, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1};

	pf_ft_mask_initializer(flags, mask);
	flags->current_argument = pf_ft_handle_modifier_d(argument, flags);
	pf_ft_handle_numbers(flags);
	return (0);
}
