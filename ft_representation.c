/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_representation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 20:25:28 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 02:51:13 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_algorithm_of_bresenham(t_basis *fdf, t_data *curr_data, int x, int y)
{
	curr_data->sign_x_y[0] = curr_data->x[0] > curr_data->x[1] ? -1 : 1;
	curr_data->sign_x_y[1] = curr_data->y[0] > curr_data->y[1] ? -1 : 1;
	mlx_pixel_put(fdf->mlx, fdf->window,
	curr_data->x[1], curr_data->y[1], COORD[x][y]->rgb);
	while (curr_data->x[0] != curr_data->x[1]
		|| curr_data->y[0] != curr_data->y[1])
	{
		mlx_pixel_put(fdf->mlx, fdf->window,
			curr_data->x[0], curr_data->y[0], COORD[x][y]->rgb);
		if ((curr_data->flag_err[1] = curr_data->flag_err[0] * 2)
			> -curr_data->delta_x_y[1])
		{
			curr_data->flag_err[0] -= curr_data->delta_x_y[1];
			curr_data->x[0] += curr_data->sign_x_y[0];
		}
		if (curr_data->flag_err[1] < curr_data->delta_x_y[0])
		{
			curr_data->flag_err[0] += curr_data->delta_x_y[0];
			curr_data->y[0] += curr_data->sign_x_y[1];
		}
	}
	return (1);
}

int		ft_calc_coord(t_basis *fdf, char cord, int x, int y)
{
	return ((cord == 'x') ?
		((((COORD[x][y]->x * cos(ANG.alpha_beta_gamma[1])
			+ (-COORD[x][y]->y * sin(ANG.alpha_beta_gamma[0]) +
		COORD[x][y]->z * fdf->scale_x_y_z_all[2]
		* cos(ANG.alpha_beta_gamma[0])) * sin(ANG.alpha_beta_gamma[1]))
		* cos(ANG.alpha_beta_gamma[2])
		+ (COORD[x][y]->y * cos(ANG.alpha_beta_gamma[0])
			+ COORD[x][y]->z *
			fdf->scale_x_y_z_all[2] * sin(ANG.alpha_beta_gamma[0]))
		* sin(ANG.alpha_beta_gamma[2]))
		* fdf->scale_x_y_z_all[3]) + (WINDOW_SIZE_X / 2))
	:
		(((-(COORD[x][y]->x * cos(ANG.alpha_beta_gamma[1])
			+ (-COORD[x][y]->y * sin(ANG.alpha_beta_gamma[0]) +
		COORD[x][y]->z * fdf->scale_x_y_z_all[2] * cos(ANG.alpha_beta_gamma[0]))
			* sin(ANG.alpha_beta_gamma[1]))
		* sin(ANG.alpha_beta_gamma[2]) +
		(COORD[x][y]->y * cos(ANG.alpha_beta_gamma[0])
			+ COORD[x][y]->z * fdf->scale_x_y_z_all[2]
			* sin(ANG.alpha_beta_gamma[0])) * cos(ANG.alpha_beta_gamma[2]))
		* fdf->scale_x_y_z_all[3]) + (WINDOW_SIZE_Y / 2)));
}

int		ft_initiialize_representation(t_basis *fdf, unsigned char fill_flag)
{
	if (fill_flag == 1)
	{
		FDO.flag_err[1] =
		((FDO.flag_err[0] =
		(FDO.delta_x_y[0] =
		abs((FDO.x[1] = ft_calc_coord(fdf, 'x', I, J + 1))
		- (FDO.x[0] = ft_calc_coord(fdf, 'x', I, J)))) -
		(FDO.delta_x_y[1] =
		abs((FDO.y[1] = ft_calc_coord(fdf, 'y', I, J + 1))
		- (FDO.y[0] = ft_calc_coord(fdf, 'y', I, J))))) * 2);
		FDO.sign_x_y[0] = FDO.x[1] < FDO.x[0] ? -1 : 1;
		return (FDO.sign_x_y[1] = FDO.y[1] < FDO.y[0] ? -1 : 1);
	}
	FDT.flag_err[1] =
	((FDT.flag_err[0] =
	(FDT.delta_x_y[0] =
	abs((FDT.x[1] = ft_calc_coord(fdf, 'x', I + 1, J))
	- (FDT.x[0] = ft_calc_coord(fdf, 'x', I, J)))) -
	(FDT.delta_x_y[1] =
	abs((FDT.y[1] = ft_calc_coord(fdf, 'y', I + 1, J))
	- (FDT.y[0] = ft_calc_coord(fdf, 'y', I, J))))) * 2);
	FDT.sign_x_y[0] = FDT.x[1] < FDT.x[0] ? -1 : 1;
	return (FDT.sign_x_y[1] = FDT.y[1] < FDT.y[0] ? -1 : 1);
}

void	ft_representation(t_basis *fdf)
{
	I = -1;
	while ((J = -1) && (++I != fdf->y[0]))
		while (++J != fdf->x[0])
		{
			if (J + 1 != fdf->x[0])
				ft_initiialize_representation(fdf, 1)
			&& ft_algorithm_of_bresenham(fdf, &fdf->drawer.one, I, J + 1);
			if (I + 1 != fdf->y[0])
				ft_initiialize_representation(fdf, 2)
			&& ft_algorithm_of_bresenham(fdf, &(fdf->drawer.two), I + 1, J);
		}
}
