/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_libft_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:47:29 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:52:00 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		pf_ft_putbase(uintmax_t num, int base, char *str, t_byte *counter)
{
	if (num >= (uintmax_t)base)
		pf_ft_putbase(num / base, base, str, counter);
	if ((num % base) < 10)
		str[(*counter)++] = (num % base) + 48;
	else
		str[(*counter)++] = (num % base) + 55;
}

char		*pf_ft_itoa_base(uintmax_t num, int base)
{
	char				*str;
	t_byte				counter;
	intmax_t			number;

	if (num == 0 || (counter = 0))
		return ("0");
	number = (intmax_t)num;
	while (number > 0)
	{
		counter++;
		number /= base;
	}
	if (!(str = (char*)malloc(sizeof(char) * (counter + 1))))
		exit(-1);
	counter = 0;
	pf_ft_putbase(num, base, str, &counter);
	str[counter] = '\0';
	return (str);
}

long		pf_ft_long_atoi(const char *str)
{
	long sign;
	long nbr;

	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	sign = (*str == '-') ? (1) : 0;
	((nbr = 0) || *str == '-' || *str == '+') ? (str++) : 0;
	while ((int)*str >= 48 && (int)*str <= 57)
		nbr = nbr * 10 + ((int)*(str++) - 48);
	return ((sign == 1) ? (-nbr) : (nbr));
}

char		*pf_ft_strsub(char const *str, unsigned int start, size_t length)
{
	char			*new;
	unsigned int	counter;

	if ((!str) || (counter = 0))
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	new[length] = 0;
	while (length--)
		new[counter++] = str[start++];
	return (new);
}

size_t		pf_ft_strlen(const char *str)
{
	ssize_t counter;

	counter = -1;
	while (str[++counter])
		;
	return (counter);
}
