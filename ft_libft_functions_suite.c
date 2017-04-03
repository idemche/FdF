/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions_suite.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 22:27:44 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 02:23:02 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	fdf_ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

double	ft_sin_cos(float x, char *inst)
{
	if (!STRCMP(inst, "cos"))
	{
		x = (x < 0.0f) ? -x : x;
		while (M_PI < x)
			x -= M_2_PI;
		return (1.0f - ((x * x) / 2.0f) *
		(1.0f - ((x * x) / 12.0f) *
		(1.0f - ((x * x) / 30.0f) *
		(1.0f - (x * x) / 56.0f))));
	}
	else if (!STRCMP(inst, "sin"))
		return (ft_sin_cos(x - M_PI_2, "cos"));
	return (0);
}

void	ft_sine_cosine(t_basis *fdf)
{
	int counter;

	counter = -1;
	while (++counter < 3)
	{
		ANG.sin_a_b_g[counter] =
		ft_sin_cos(ANG.alpha_beta_gamma[counter], "sin");
		ANG.cos_a_b_g[counter] =
		ft_sin_cos(ANG.alpha_beta_gamma[counter], "cos");
	}
}
