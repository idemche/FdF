/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_wchar_to_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:50:01 by idemchen          #+#    #+#             */
/*   Updated: 2017/02/17 21:49:37 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** 0xxxxxxx // 0x00
**	No action
** 110xxxxx 10xxxxxx // 0xC0 0x80
** I move 6 on the right and add 11000000
** I filter by 111111 and add 10000000
** 1110xxxx 10xxxxxx 10xxxxxx // 0xE0 0x80 0x80
** I move 12 on the right and add 11100000
** I move 6, I filter by 111111 and I add 10000000
** I filter by 111111 and I add 10000000
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx // 0xF0 0x80 0x80 0x80
** I move 18 on the right and add 11110000
** I move 12 on the right, I filter by 111111 and I add 10000000
** I move 6 on the right, I filter by 111111 and I add 10000000
** I filter by 111111 and add 10000000
*/

int		pf_ft_wchar_str_initializer(wchar_t wchar, int counter, char *new)
{
	short		length;

	length = pf_ft_wchar_length(wchar);
	if (length == 1)
		new[counter++] = wchar;
	else if (length == 2)
	{
		new[counter++] = (wchar >> 6) + 0xC0;
		new[counter++] = (wchar & 0x3F) + 0x80;
	}
	else if (length == 3)
	{
		new[counter++] = (wchar >> 12) + 0xE0;
		new[counter++] = ((wchar >> 6) & 0x3F) + 0x80;
		new[counter++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		new[counter++] = (wchar >> 18) + 0xF0;
		new[counter++] = ((wchar >> 12) & 0x3F) + 0x80;
		new[counter++] = ((wchar >> 6) & 0x3F) + 0x80;
		new[counter++] = (wchar & 0x3F) + 0x80;
	}
	return (counter);
}

char	*pf_ft_wchar_to_char(wchar_t *wstr)
{
	char	*new;
	int		counter;
	int		iterator;
	int		length;

	if (!wstr)
		return (0);
	counter = 0;
	iterator = 0;
	length = pf_ft_wchar_length_inbyte(wstr);
	if (!(new = (char*)malloc(sizeof(char) * length)))
		return (NULL);
	new[length] = '\0';
	while (wstr[iterator])
		counter = pf_ft_wchar_str_initializer(wstr[iterator++], counter, new);
	return (new);
}
