/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 18:07:17 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 02:23:46 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_inbase(char c, int base, char let)
{
	return ((base < 11) ? (c >= '0' && c <= '9')
		: ((c >= '0' && c <= '9')
			|| (c >= let && c <= (let + base - 10))));
}

static char	check_case(char *str, int base)
{
	int	counter;

	counter = -1;
	while (str[++counter])
		if (str[counter] >= 'A' && str[counter] <= 'A' + base)
			return ('A');
		else if (str[counter] >= 'a' && str[counter] <= 'a' + base)
			return ('a');
	return ('A');
}

int			ft_atoi_base(const char *str, int base)
{
	int		result;
	int		minus;
	char	chr;

	if ((result = 0) || base < 2 || base > 16)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == '\v')
		str++;
	minus = (*str == '-') ? 1 : 0;
	chr = check_case((char*)str, base);
	(*str == '-' || *str == '+') ? str++ : 0;
	while (ft_inbase(*str, base, chr))
	{
		result = (*str - chr >= 0) ?
		result * base + (*str - chr + 10) : result * base + (*str - '0');
		str++;
	}
	return ((minus == 0) ? result : -result);
}

char		*fdf_ft_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (*s != ch)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

int			fdf_ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (*u1 == *u2)
	{
		if (*u1 == '\0')
			return (0);
		u1++;
		u2++;
	}
	return (*u1 - *u2);
}
