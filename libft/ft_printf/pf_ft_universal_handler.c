/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_universal_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:49:27 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:49:05 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pf_ft_mask_initializer(t_variables *flags, int *mask)
{
	flags->allflags.sharp *= mask[0];
	flags->allflags.zero *= mask[1];
	flags->allflags.minus *= mask[2];
	flags->allflags.plus *= mask[3];
	flags->allflags.space *= mask[4];
	flags->allflags.hh *= mask[5];
	flags->allflags.h *= mask[6];
	flags->allflags.ll *= mask[7];
	flags->allflags.l *= mask[8];
	flags->allflags.j *= mask[9];
	flags->allflags.z *= mask[10];
}

int		pf_ft_handle_char(t_variables *flags)
{
	if (flags->allflags.prec != 0 && (flags->specifier != 'C'
		|| (flags->specifier == 'c' && flags->allflags.l == 1)))
		pf_ft_handle_precision(flags);
	else if (flags->specifier == 'S' || (flags->specifier == 's'
		&& flags->allflags.l == 1) || flags->specifier == 'C'
		|| (flags->specifier == 'c' && flags->allflags.l == 1))
		flags->current_argument = pf_ft_wchar_to_char(flags->wchar_argument);
	if (flags->allflags.width > 0)
		pf_ft_char_n_width(flags);
	if (flags->allflags.width == 0)
		pf_ft_print_argument(flags);
	return (1);
}

int		pf_ft_handle_numbers(t_variables *flags)
{
	int counter;

	counter = -1;
	if (flags->allflags.prec == -1 && flags->current_argument[0] == 48
		&& !(flags->allflags.sharp == 1 &&
			(flags->specifier == 'o' || flags->specifier == 'O'
				|| flags->specifier == 'p')))
		flags->current_argument = "\0";
	if (flags->allflags.width > 0)
		pf_ft_num_n_width(flags);
	else if (flags->allflags.width == 0 && flags->allflags.prec > 0)
		pf_ft_precision_no_width(flags);
	if (flags->allflags.prec <= 0 && flags->allflags.width == 0)
		pf_ft_space_sharp_plus(flags);
	while (flags->current_argument[++counter] != 0
		&& flags->allflags.width == 0)
		pf_ft_print_buffer(flags, flags->current_argument[counter]);
	pf_ft_allmighty_free(flags);
	return (1);
}
