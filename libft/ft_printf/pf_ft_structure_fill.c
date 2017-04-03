/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_structure_fill.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:48:40 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:51:06 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_byte	pf_ft_initialize_further(t_conversions *conversion)
{
	conversion->symbol[12] = 'c';
	conversion->function[12] = &pf_ft_handle_c;
	conversion->symbol[13] = 'C';
	conversion->function[13] = &pf_ft_handle_wchar;
	conversion->symbol[14] = '\0';
	conversion->function[14] = NULL;
	return (1);
}

t_byte			pf_ft_conversions_initializer(t_conversions *conversion)
{
	conversion->symbol[0] = 's';
	conversion->function[0] = &pf_ft_handle_s;
	conversion->symbol[1] = 'S';
	conversion->function[1] = &pf_ft_handle_wchar_s;
	conversion->symbol[2] = 'p';
	conversion->function[2] = &pf_ft_handle_p;
	conversion->symbol[3] = 'd';
	conversion->function[3] = &pf_ft_handle_d;
	conversion->symbol[4] = 'D';
	conversion->function[4] = &pf_ft_handle_wchar_d;
	conversion->symbol[5] = 'i';
	conversion->function[5] = &pf_ft_handle_d;
	conversion->symbol[6] = 'o';
	conversion->function[6] = &pf_ft_handle_o;
	conversion->symbol[7] = 'O';
	conversion->function[7] = &pf_ft_handle_wchar_o;
	conversion->symbol[8] = 'u';
	conversion->function[8] = &pf_ft_handle_u;
	conversion->symbol[9] = 'U';
	conversion->function[9] = &pf_ft_handle_wchar_u;
	conversion->symbol[10] = 'x';
	conversion->function[10] = &pf_ft_handle_x;
	conversion->symbol[11] = 'X';
	conversion->function[11] = &pf_ft_handle_wchar_x;
	return (pf_ft_initialize_further(conversion));
}

void			pf_ft_allflags_fill(t_variables *flags)
{
	flags->allflags.prec = 0;
	flags->allflags.width = 0;
	flags->allflags.minus = 0;
	flags->allflags.plus = 0;
	flags->allflags.space = 0;
	flags->allflags.sharp = 0;
	flags->allflags.zero = 0;
	flags->allflags.hh = 0;
	flags->allflags.h = 0;
	flags->allflags.ll = 0;
	flags->allflags.l = 0;
	flags->allflags.j = 0;
	flags->allflags.z = 0;
}

int				pf_ft_multichecker(t_variables *flags)
{
	flags->current_index = 0;
	pf_ft_allflags_fill(flags);
	while (flags->current[flags->current_index] == '-'
		|| flags->current[flags->current_index] == '+'
		|| flags->current[flags->current_index] == ' '
		|| flags->current[flags->current_index] == '#'
		|| flags->current[flags->current_index] == '0'
		|| flags->current[flags->current_index] == 'h'
		|| flags->current[flags->current_index] == 'l'
		|| flags->current[flags->current_index] == '.'
		|| flags->current[flags->current_index] == 'j'
		|| flags->current[flags->current_index] == 'z'
		|| (flags->current[flags->current_index] >= '0'
			&& flags->current[flags->current_index] <= '9'))
	{
		pf_ft_flag_checker(flags);
		pf_ft_width_checker(flags);
		pf_ft_precision_checker(flags);
		pf_ft_modifier_checker(flags);
	}
	return ((flags->current_index == pf_ft_strlen(flags->current))
		? (-1) : (1));
}

int				pf_ft_arguments_handler(va_list *argument, t_variables *flags)
{
	int				count;
	t_conversions	conversion;

	if (pf_ft_multichecker(flags) < 0 || (count = 0))
		return (-1);
	pf_ft_conversions_initializer(&conversion);
	flags->specifier = flags->current[flags->current_index];
	flags->wchar_argument = NULL;
	flags->current_argument = NULL;
	while (conversion.symbol[count] != flags->specifier
		&& conversion.symbol[count] != 0)
		count++;
	return ((conversion.symbol[count] == 0) ? pf_ft_handle_undefined(flags)
		: conversion.function[count](argument, flags));
}
