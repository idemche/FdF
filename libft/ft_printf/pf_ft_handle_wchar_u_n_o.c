/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_handle_wchar_u_n_o.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:47:05 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:46:41 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*pf_ft_handle_modifier_wu_wo(va_list *argument, t_variables *flags)
{
	intmax_t	processed;

	if (flags->allflags.z == 1)
		processed = (uintmax_t)va_arg(*argument, size_t);
	else if (flags->allflags.j == 1)
		processed = va_arg(*argument, uintmax_t);
	else if (flags->allflags.l == 1)
		processed = (uintmax_t)va_arg(*argument, unsigned long);
	else if (flags->allflags.ll == 1)
		processed = (uintmax_t)va_arg(*argument, unsigned long long);
	else if (flags->allflags.h == 1)
		processed = (uintmax_t)va_arg(*argument, unsigned);
	else if (flags->allflags.hh == 1)
		processed = (uintmax_t)va_arg(*argument, unsigned);
	else
		processed = (uintmax_t)va_arg(*argument, unsigned long);
	if (flags->specifier == 'U')
		return (pf_ft_itoa_base(processed, 10));
	if (flags->specifier == 'O')
		return (pf_ft_itoa_base(processed, 8));
	return (NULL);
}

int			pf_ft_handle_wchar_u(va_list *argument, t_variables *flags)
{
	static int	mask[11] = {2, 1, 1, 1, 1, 2, 2, 1, 2, 1, 1};

	pf_ft_mask_initializer(flags, mask);
	flags->current_argument = pf_ft_handle_modifier_wu_wo(argument, flags);
	pf_ft_handle_numbers(flags);
	return (0);
}

int			pf_ft_handle_wchar_o(va_list *argument, t_variables *flags)
{
	static int	mask[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	pf_ft_mask_initializer(flags, mask);
	flags->current_argument = pf_ft_handle_modifier_wu_wo(argument, flags);
	if (flags->allflags.prec == -1 && flags->current_argument[0] != 48
		&& flags->allflags.sharp == 1)
		flags->allflags.prec = 0;
	pf_ft_handle_numbers(flags);
	return (0);
}
