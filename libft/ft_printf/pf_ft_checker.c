/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:37:05 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:44:43 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		pf_ft_flag_checker(t_variables *flags)
{
	if (flags->current[flags->current_index] == '0'
		|| flags->current[flags->current_index] == '#'
		|| flags->current[flags->current_index] == ' '
		|| flags->current[flags->current_index] == '+'
		|| flags->current[flags->current_index] == '-')
	{
		(flags->current[flags->current_index] == '-') ?
		flags->allflags.minus = 1 : 0;
		(flags->current[flags->current_index] == '+') ?
		flags->allflags.plus = 1 : 0;
		(flags->current[flags->current_index] == ' ') ?
		flags->allflags.space = 1 : 0;
		(flags->current[flags->current_index] == '#') ?
		flags->allflags.sharp = 1 : 0;
		(flags->current[flags->current_index] == '0') ?
		flags->allflags.zero = 1 : 0;
		flags->current_index++;
	}
}

void		pf_ft_width_checker(t_variables *flags)
{
	char			*str;
	int				c;

	if (flags->current[flags->current_index] > '0'
		&& flags->current[flags->current_index] <= '9')
	{
		c = flags->current_index;
		while (flags->current[flags->current_index] >= '0'
		&& flags->current[flags->current_index] <= '9')
			flags->current_index++;
		if (flags->current_index - c > 0)
		{
			flags->allflags.width = 0;
			str = pf_ft_strsub(flags->current, c, flags->current_index - c);
			flags->allflags.width = pf_ft_long_atoi((const char*)str);
			free(str);
		}
	}
}

void		pf_ft_precision_checker(t_variables *flags)
{
	int				c;
	char			*str;

	if (flags->current[flags->current_index] == '.')
	{
		flags->allflags.prec = 0;
		c = ++flags->current_index;
		while (flags->current[flags->current_index] >= '0'
		&& flags->current[flags->current_index] <= '9')
			flags->current_index++;
		if (flags->current_index - c > 0)
		{
			str = pf_ft_strsub(flags->current, c, flags->current_index - c);
			flags->allflags.prec = pf_ft_long_atoi((const char*)str);
			free(str);
		}
		(flags->allflags.prec == 0) ? (flags->allflags.prec = -1) : (0);
	}
}

void		pf_ft_modifier_checker(t_variables *flags)
{
	while (flags->current[flags->current_index] == 'h'
		|| flags->current[flags->current_index] == 'l'
		|| flags->current[flags->current_index] == 'j'
		|| flags->current[flags->current_index] == 'z')
	{
		if (flags->current[flags->current_index] == 'h' &&
			flags->current[flags->current_index + 1] == 'h')
			(flags->allflags.hh = 1) && (++flags->current_index);
		else if (flags->current[flags->current_index] == 'h')
			flags->allflags.h = 1;
		if (flags->current[flags->current_index] == 'l' &&
			flags->current[flags->current_index + 1] == 'l')
			(flags->allflags.ll = 1) && (++flags->current_index);
		else if (flags->current[flags->current_index] == 'l')
			flags->allflags.l = 1;
		flags->allflags.j = (flags->current[flags->current_index] == 'j')
		? 1 : 0;
		flags->allflags.z = (flags->current[flags->current_index] == 'z') ?
		1 : 0;
		flags->current_index++;
	}
}
