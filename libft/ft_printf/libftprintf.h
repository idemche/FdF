/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 17:02:50 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 03:38:23 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef unsigned char	t_byte;
typedef	struct	s_control_structure
{
	int		(*function[16])();
	char	symbol[16];
}				t_conversions;

typedef struct	s_flags
{
	int	prec;
	int	width;
	int	minus : 3;
	int	plus : 3;
	int	space : 3;
	int	sharp : 3;
	int	zero : 3;
	int	hh : 3;
	int	h : 3;
	int	ll : 3;
	int	l : 3;
	int	j : 3;
	int	z : 3;
}				t_allflags;

typedef	struct	s_structure
{
	int			result;
	char		*current;
	char		*current_argument;
	wchar_t		*wchar_argument;
	unsigned	current_index;
	char		specifier;
	char		sign;
	int			g_buf_ind;
	char		g_buf[4096];
	t_allflags	allflags;
}				t_variables;

int				ft_printf(const char *format, ...);
void			pf_ft_allmighty_free(t_variables *flags);
int				pf_ft_multichecker(t_variables *flags);
void			pf_ft_allflags_fill(t_variables *flags);
void			pf_ft_flag_checker(t_variables *flags);
void			pf_ft_width_checker(t_variables *fl);
void			pf_ft_precision_checker(t_variables *flags);
void			pf_ft_modifier_checker(t_variables *flags);
void			pf_ft_putbase(uintmax_t num, int base,
	char *str, t_byte *counter);
char			*pf_ft_strsub(char const *str,
	unsigned int start, size_t length);
char			*pf_ft_itoa_base(uintmax_t num, int base);
uintmax_t		pf_ft_sign_flag(t_variables *flags, intmax_t num);
size_t			pf_ft_strlen(const char *str);
long			pf_ft_long_atoi(const char *str);
char			*pf_ft_lower_string(char *str);
int				pf_ft_wchar_length(wchar_t wchar);
size_t			pf_ft_wchar_length_inbyte(wchar_t *wstr);
size_t			pf_ft_wstr_length(wchar_t *wstr);
char			*pf_ft_wstr_sub(wchar_t *wstr,
	unsigned int start, size_t length);
char			*pf_ft_free_sub(char const *str, unsigned int start,
	size_t length);
char			*pf_ft_wchar_to_char(wchar_t *wstr);
int				pf_ft_wchar_str_initializer(wchar_t wchar,
	int counter, char *new);
t_byte			pf_ft_conversions_initializer(t_conversions *conversion);
int				pf_ft_arguments_handler(va_list *argument, t_variables *flags);
void			pf_ft_mask_initializer(t_variables *flags, int *mask);
int				pf_ft_handle_char(t_variables *flags);
int				pf_ft_handle_numbers(t_variables *flags);

int				pf_ft_handle_c(va_list *argument, t_variables *flags);
int				pf_ft_handle_wchar(va_list *argument, t_variables *flags);
int				pf_ft_handle_modifier_wc(va_list *argument, t_variables *flags);

int				pf_ft_handle_s(va_list *argument, t_variables *flags);
int				pf_ft_handle_wchar_s(va_list *argument, t_variables *flags);

int				pf_ft_handle_d(va_list *argument, t_variables *flags);
int				pf_ft_handle_wchar_d(va_list *argument, t_variables *flags);
char			*pf_ft_handle_modifier_d(va_list *argument, t_variables *flags);
int				pf_ft_handle_o(va_list *argument, t_variables *flags);
int				pf_ft_handle_u(va_list *argument,
	t_variables *flags);
char			*pf_ft_handle_modifier_u_o(va_list *argument,
	t_variables *flags);
int				pf_ft_handle_wchar_o(va_list *argument, t_variables *flags);
int				pf_ft_handle_wchar_u(va_list *argument, t_variables *flags);
char			*pf_ft_handle_modifier_wu_wo(va_list *argument,
	t_variables *flags);
int				pf_ft_handle_x(va_list *argument, t_variables *flags);
int				pf_ft_handle_wchar_x(va_list *argument, t_variables *flags);
char			*pf_ft_handle_modifier_x(va_list *argument, t_variables *flags);
int				pf_ft_handle_p(va_list *argument, t_variables *flags);
int				pf_ft_handle_undefined(t_variables *flags);
void			pf_ft_space_sharp_plus(t_variables *flags);
void			pf_ft_handle_sharp(t_variables *fl);
void			pf_ft_handle_precision(t_variables *flags);
void			pf_ft_precision_no_width(t_variables *flags);
void			pf_ft_num_n_precision(int zero_length, t_variables *flags);
void			pf_ft_num_n_zero(t_variables *flags);
void			pf_ft_num_n_minus(t_variables *flags);
void			pf_ft_num_n_width(t_variables *flags);
void			pf_ft_print_argument(t_variables *flags);
void			pf_ft_char_n_width(t_variables *flags);
void			pf_ft_char_n_minus(t_variables *flags);
void			pf_ft_char_n_zero(t_variables *flags);
ssize_t			pf_ft_putbuffer(char *buffer, int num);
void			pf_ft_print_buffer(t_variables *flags, char chr);
void			pf_ft_print_buff_null(t_variables *flags);
void			pf_ft_print_symbol(t_variables *flags);
void			pf_ft_buf_fill(t_variables *flags, int size);

#endif
