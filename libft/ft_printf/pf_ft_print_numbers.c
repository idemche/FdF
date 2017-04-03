/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:48:11 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:47:46 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pf_ft_precision_no_width(t_variables *flags)
{
	int len_n_prec[2];

	len_n_prec[0] = pf_ft_strlen(flags->current_argument);
	len_n_prec[1] = flags->allflags.prec;
	pf_ft_space_sharp_plus(flags);
	while (len_n_prec[1] > len_n_prec[0]-- && len_n_prec[0] > 0)
		len_n_prec[1]--;
	if ((unsigned long)flags->allflags.prec > flags->allflags.width
		+ pf_ft_strlen(flags->current_argument))
		while (++len_n_prec[0] < len_n_prec[1])
			pf_ft_print_buffer(flags, 48);
}

void	pf_ft_num_n_precision(int zero_length, t_variables *flags)
{
	int length;

	length = pf_ft_strlen(flags->current_argument);
	if (flags->allflags.plus == 1 || flags->allflags.space == 1
		|| flags->sign == '-' || (flags->allflags.sharp == 1 &&
		flags->allflags.prec <= length && (flags->specifier == 'o'
			|| flags->specifier == 'O')))
		zero_length--;
	if (flags->allflags.sharp == 1 && (flags->specifier == 'x'
		|| flags->specifier == 'X' || flags->specifier == 'p'))
		zero_length -= 2;
	while (flags->allflags.prec > length++)
		zero_length--;
	if (flags->allflags.prec < flags->allflags.width
		+ (int)pf_ft_strlen(flags->current_argument))
	{
		while (zero_length-- > 0)
		{
			if (flags->allflags.zero == 1 && flags->allflags.prec == 0)
				pf_ft_print_buffer(flags, 48);
			else
				pf_ft_print_buffer(flags, ' ');
		}
	}
}

void	pf_ft_num_n_zero(t_variables *flags)
{
	int c_len_zlen[3];

	c_len_zlen[0] = -1;
	c_len_zlen[1] = pf_ft_strlen(flags->current_argument);
	c_len_zlen[2] = flags->allflags.width - c_len_zlen[1];
	if (flags->allflags.zero == 1)
	{
		pf_ft_space_sharp_plus(flags);
		pf_ft_num_n_precision(c_len_zlen[2], flags);
	}
	else
	{
		pf_ft_num_n_precision(c_len_zlen[2], flags);
		pf_ft_space_sharp_plus(flags);
	}
	while (flags->allflags.prec > c_len_zlen[1]++)
		pf_ft_print_buffer(flags, 48);
	while (flags->current_argument[++c_len_zlen[0]])
		pf_ft_print_buffer(flags, flags->current_argument[c_len_zlen[0]]);
}

void	pf_ft_num_n_minus(t_variables *flags)
{
	int c_len_zlen[3];

	c_len_zlen[0] = -1;
	c_len_zlen[1] = pf_ft_strlen(flags->current_argument);
	c_len_zlen[2] = flags->allflags.width - c_len_zlen[1];
	flags->allflags.zero = 0;
	pf_ft_space_sharp_plus(flags);
	while (flags->allflags.prec > c_len_zlen[1]++)
		pf_ft_print_buffer(flags, 48);
	while (flags->current_argument[++c_len_zlen[0]])
		pf_ft_print_buffer(flags, flags->current_argument[c_len_zlen[0]]);
	pf_ft_num_n_precision(c_len_zlen[2], flags);
}

void	pf_ft_num_n_width(t_variables *flags)
{
	int count_len[2];

	count_len[0] = -1;
	count_len[1] = pf_ft_strlen(flags->current_argument);
	if (count_len[1] < flags->allflags.width)
		(flags->allflags.minus == 1)
	? pf_ft_num_n_minus(flags) : pf_ft_num_n_zero(flags);
	else
	{
		pf_ft_space_sharp_plus(flags);
		while (flags->allflags.prec > count_len[1]++)
			pf_ft_print_buffer(flags, 48);
		while (flags->current_argument[++count_len[0]])
			pf_ft_print_buffer(flags, flags->current_argument[count_len[0]]);
	}
}
