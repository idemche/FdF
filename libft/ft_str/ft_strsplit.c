/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:38:27 by idemchen          #+#    #+#             */
/*   Updated: 2017/01/02 18:20:06 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_wordcount(const char *s, char c)
{
	int count;
	int quantity;

	count = 0;
	quantity = 0;
	while (s[count] != '\0')
	{
		while (s[count++] == c)
			;
		while (s[count] != c && s[count + 1] != '\0')
		{
			count++;
		}
		quantity++;
		count++;
	}
	return (quantity);
}

static char		*ft_to_pointer(const char *s, int *start, char c)
{
	int		link;
	char	*pointer;

	pointer = NULL;
	while (s[*start])
	{
		if (s[*start] == c)
			(*start)++;
		else if (s[*start] != c)
		{
			link = *start;
			while (s[*start] != c && s[*start])
				(*start)++;
			pointer = ft_strsub(s, link, (*start) - link);
			break ;
		}
	}
	return (pointer);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		count;
	int		point;
	int		words;

	if (s == NULL)
		return (NULL);
	words = ft_wordcount(s, c);
	if ((str = (char **)malloc(sizeof(char *) * (words + 1))) == NULL)
		return (NULL);
	count = 0;
	point = 0;
	while (count < words)
	{
		str[count] = ft_to_pointer(s, &point, c);
		count++;
	}
	str[count] = 0;
	return (str);
}
