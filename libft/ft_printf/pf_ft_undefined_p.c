/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_undefined_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:49:16 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:51:14 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pf_ft_handle_p(va_list *argument, t_variables *flags)
{
	static int	mask[11] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

	flags->allflags.sharp = 1;
	pf_ft_mask_initializer(flags, mask);
	flags->current_argument =
	pf_ft_lower_string(pf_ft_itoa_base((uintmax_t)va_arg(*argument, void*),
		16));
	if (flags->allflags.prec == -1 && flags->current_argument[0] == 48)
	{
		pf_ft_print_buffer(flags, 48);
		pf_ft_print_buffer(flags, 'x');
	}
	else
		pf_ft_handle_numbers(flags);
	return (0);
}

int		pf_ft_handle_undefined(t_variables *flags)
{
	static int	mask[11] = {2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};
	char		chr[2];

	flags->allflags.prec = 0;
	if (flags->specifier == 0)
	{
		(flags->result = 0);
		return (flags->result);
	}
	chr[0] = flags->specifier;
	chr[1] = '\0';
	flags->current_argument = chr;
	pf_ft_mask_initializer(flags, mask);
	return (pf_ft_handle_char(flags));
}
