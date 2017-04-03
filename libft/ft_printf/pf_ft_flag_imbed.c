/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_flag_imbed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:45:38 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:45:15 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pf_ft_handle_sharp(t_variables *fl)
{
	if ((fl->allflags.sharp == 1 && fl->current_argument[0] != 48
		&& fl->allflags.prec != -1) || fl->specifier == 'p')
	{
		if (fl->specifier == 'o' || fl->specifier == 'O' || fl->specifier == 'x'
			|| fl->specifier == 'X' || fl->specifier == 'p')
		{
			if ((fl->specifier == 'x' && fl->current_argument[0] != 48)
				|| fl->specifier == 'p')
			{
				pf_ft_print_buffer(fl, 48);
				pf_ft_print_buffer(fl, 'x');
			}
			else if (fl->specifier == 'X' && fl->current_argument[0] != 48)
			{
				pf_ft_print_buffer(fl, 48);
				pf_ft_print_buffer(fl, 'X');
			}
			else if ((fl->specifier == 'o' || fl->specifier == 'O') &&
				fl->allflags.prec <= (int)pf_ft_strlen(fl->current_argument))
				pf_ft_print_buffer(fl, 48);
			else if ((fl->specifier == 'o' || fl->specifier == 'O')
				&& fl->allflags.prec == -1)
				pf_ft_print_buffer(fl, 48);
		}
	}
}

void	pf_ft_space_sharp_plus(t_variables *flags)
{
	if (flags->allflags.plus == 1 || flags->allflags.space == 1)
	{
		if (flags->specifier == 'D' || flags->specifier == 'i'
			|| flags->specifier == 'd')
		{
			if (flags->sign != '-' && flags->allflags.space == 1
				&& flags->allflags.plus == 0)
				pf_ft_print_buffer(flags, 32);
			if (flags->allflags.plus == 1 && flags->sign == '+'
				&& (flags->current_argument[0] >= '0'
					&& flags->current_argument[0] <= '9'))
				pf_ft_print_buffer(flags, '+');
		}
	}
	(flags->sign == '-') ? pf_ft_print_buffer(flags, '-') : 0;
	pf_ft_handle_sharp(flags);
}

void	pf_ft_handle_precision(t_variables *flags)
{
	if (flags->allflags.prec == -1)
		flags->current_argument = "\0";
	else if (flags->specifier == 'S' || (flags->specifier == 's'
		&& flags->allflags.l == 1))
		flags->current_argument =
	pf_ft_wstr_sub(flags->wchar_argument, 0, flags->allflags.prec);
	else if (flags->specifier == 's')
		flags->current_argument =
	pf_ft_strsub(flags->current_argument, 0, flags->allflags.prec);
}
