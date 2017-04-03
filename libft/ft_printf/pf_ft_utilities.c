/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:49:39 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:49:17 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

uintmax_t	pf_ft_sign_flag(t_variables *flags, intmax_t num)
{
	flags->sign = '+';
	(num < 0) ? (flags->sign = '-')
	&& (num = -num) : 0;
	return ((uintmax_t)num);
}

void		pf_ft_allmighty_free(t_variables *flags)
{
	if (flags->allflags.prec >= 0 && flags->current_argument != NULL
		&& flags->current_argument[0] != 0 &&
		flags->current_argument[0] != 48)
	{
		if (flags->specifier == 'x' || flags->specifier == 'X'
			|| flags->specifier == 'o' || flags->specifier == 'O'
			|| flags->specifier == 'u' || flags->specifier == 'U'
			|| flags->specifier == 'd' || flags->specifier == 'D'
			|| flags->specifier == 'p' || flags->specifier == 'S'
			|| flags->specifier == 'i' || (flags->specifier == 's'
				&& flags->allflags.prec
				< (int)pf_ft_strlen(flags->current_argument)
				&& flags->allflags.prec > 0) || flags->specifier == 'C'
			|| (flags->specifier == 'c' && flags->allflags.l == 1))
			free(flags->current_argument);
	}
}
