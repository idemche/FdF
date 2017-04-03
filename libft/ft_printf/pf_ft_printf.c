/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:48:19 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 22:02:18 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list			argument;
	t_variables		flags;
	int				count;

	va_start(argument, format);
	flags.result = 0;
	count = -1;
	pf_ft_buf_fill(&flags, 4096);
	while (format[++count])
	{
		if (format[count] == '%')
		{
			flags.current = (char*)(&format[++count]);
			if (pf_ft_arguments_handler(&argument, &flags) < 0)
				break ;
			count += flags.current_index;
		}
		else if (format[count] != '%' && format[count])
			pf_ft_print_buffer(&flags, format[count]);
	}
	(flags.g_buf_ind > 0) ? pf_ft_print_symbol(&flags) : 0;
	va_end(argument);
	return (flags.result);
}
