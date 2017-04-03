/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_libft_functions_suite.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:47:52 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:47:27 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pf_ft_wchar_length(wchar_t wchar)
{
	if (wchar <= 0x7F)
		return (1);
	else if (wchar <= 0x7FF)
		return (2);
	else if (wchar <= 0x7FFFF)
		return (3);
	else
		return (4);
}

size_t	pf_ft_wstr_length(wchar_t *wstr)
{
	size_t length;

	length = 0;
	if (!wstr)
		return (0);
	while (*(wstr++))
		length++;
	return (length);
}

size_t	pf_ft_wchar_length_inbyte(wchar_t *wstr)
{
	size_t length;
	size_t byte_length;

	length = pf_ft_wstr_length(wstr);
	byte_length = 0;
	while (length-- > 0)
	{
		byte_length += pf_ft_wchar_length(*wstr);
		wstr++;
	}
	return (byte_length);
}

char	*pf_ft_free_sub(char const *str, unsigned int start,
	size_t length)
{
	char	*new;
	char	*temp;
	int		counter;

	if ((!str) || !(new = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	new[length] = '\0';
	temp = (char*)str;
	counter = 0;
	while (length--)
		new[counter++] = str[start++];
	free(temp);
	return (new);
}

char	*pf_ft_wstr_sub(wchar_t *wstr, unsigned int start, size_t length)
{
	char		*new;
	unsigned	counter;
	unsigned	inner_length;

	inner_length = 0;
	counter = 0;
	while (wstr[counter] != '\0'
		&& length >= (unsigned)pf_ft_wchar_length(wstr[counter]))
	{
		length -= pf_ft_wchar_length(wstr[counter]);
		inner_length += pf_ft_wchar_length(wstr[counter++]);
	}
	new = pf_ft_wchar_to_char(wstr);
	return (pf_ft_free_sub(new, start, inner_length));
}
