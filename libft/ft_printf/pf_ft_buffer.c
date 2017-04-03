/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:52:32 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:44:11 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	pf_ft_buf_fill(t_variables *flags, int size)
{
	int		count;

	count = 0;
	flags->g_buf_ind = 0;
	while (count < size)
		flags->g_buf[count++] = 0;
}

void	pf_ft_print_symbol(t_variables *flags)
{
	flags->result += write(1, flags->g_buf, flags->g_buf_ind);
	pf_ft_buf_fill(flags, 4096);
}

void	pf_ft_print_buff_null(t_variables *flags)
{
	char		*str;
	unsigned	counter;

	counter = 0;
	str = "(null)";
	while (str[counter])
		pf_ft_print_buffer(flags, str[counter++]);
}

void	pf_ft_print_buffer(t_variables *flags, char chr)
{
	flags->g_buf[(flags->g_buf_ind)++] = chr;
	(flags->g_buf_ind == 4096) ? pf_ft_print_symbol(flags) : 0;
}
