/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:41:20 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:47:37 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		pf_ft_print_argument(t_variables *flags)
{
	size_t	length;
	int		counter;

	if ((counter = -1) && ((flags->specifier == 's' && flags->allflags.l == 1)
		|| flags->specifier == 'S' || (flags->specifier == 'c'
			&& flags->allflags.l == 1) || flags->specifier == 'C'))
	{
		if (flags->current_argument != NULL)
		{
			if (flags->current_argument[0] == 0 && (flags->specifier == 'C' ||
				(flags->specifier == 'c' && flags->allflags.l == 1)))
				pf_ft_print_buffer(flags, 0);
			length = pf_ft_strlen(flags->current_argument);
			while (length-- > 0)
				pf_ft_print_buffer(flags, flags->current_argument[++counter]);
		}
		else if (flags->allflags.prec != -1)
			pf_ft_print_buff_null(flags);
	}
	else
		while (flags->current_argument[++counter])
			pf_ft_print_buffer(flags, flags->current_argument[counter]);
	pf_ft_allmighty_free(flags);
}

void		pf_ft_char_n_minus(t_variables *flags)
{
	int		space_num;

	space_num = flags->allflags.width - pf_ft_strlen(flags->current_argument);
	if ((flags->specifier == 'c' && flags->current_argument[0] == 0)
		|| (flags->specifier == 'C' && flags->current_argument[0] == 0))
		space_num--;
	pf_ft_print_argument(flags);
	while (space_num-- > 0)
		pf_ft_print_buffer(flags, 32);
}

void		pf_ft_char_n_zero(t_variables *flags)
{
	int		space_num;

	space_num = flags->allflags.width - pf_ft_strlen(flags->current_argument);
	if ((flags->specifier == 'c' && flags->current_argument[0] == 0)
		|| (flags->specifier == 'C' && flags->current_argument[0] == 0))
		space_num--;
	while (space_num-- > 0)
	{
		if (flags->allflags.zero == 1 && flags->allflags.prec <= 0)
			pf_ft_print_buffer(flags, 48);
		else
			pf_ft_print_buffer(flags, 32);
	}
	pf_ft_print_argument(flags);
}

void		pf_ft_char_n_width(t_variables *flags)
{
	int counter;

	counter = (flags->current_argument)
	? pf_ft_strlen(flags->current_argument) : 0;
	if (counter < flags->allflags.width)
		(flags->allflags.minus == 1)
	? pf_ft_char_n_minus(flags) : pf_ft_char_n_zero(flags);
	else
		pf_ft_print_argument(flags);
}
