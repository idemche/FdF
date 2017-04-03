/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 01:53:56 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 03:19:37 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key_press(int key, t_basis *fdf)
{
	(key == 53 || key == 65307) ? exit(1) : 23;
	fdf->flag.frw = (key == 126) ? 1 : 0;
	fdf->flag.back = (key == 125) ? 1 : 0;
	fdf->flag.left = (key == 124) ? 1 : 0;
	fdf->flag.right = (key == 123) ? 1 : 0;
	fdf->flag.down = (key == 78) ? 1 : 0;
	fdf->flag.zoomin = (key == 116) ? 1 : 0;
	fdf->flag.zoomout = (key == 121) ? 1 : 0;
	fdf->flag.up = (key == 69) ? 1 : 0;
	return (0);
}

int		ft_key_release(int key, t_basis *fdf)
{
	(key == 126) ? fdf->flag.frw = 0 : 23;
	(key == 125) ? fdf->flag.back = 0 : 23;
	(key == 124) ? fdf->flag.left = 0 : 23;
	(key == 123) ? fdf->flag.right = 0 : 23;
	(key == 78) ? fdf->flag.down = 0 : 23;
	(key == 116) ? fdf->flag.zoomin = 0 : 23;
	(key == 121) ? fdf->flag.zoomout = 0 : 23;
	(key == 69) ? fdf->flag.up = 0 : 23;
	return (0);
}

int		ft_clear_and_draw(t_basis *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->window);
	ft_representation(fdf);
	return (1);
}

int		ft_check_flag(t_basis *fdf)
{
	if (fdf->flag.frw == 1)
		(ANG.alpha_beta_gamma[0] += 3 * RADIAN) && ft_clear_and_draw(fdf);
	if (fdf->flag.back == 1)
		(ANG.alpha_beta_gamma[0] -= 3 * RADIAN) && ft_clear_and_draw(fdf);
	if (fdf->flag.left == 1)
		(ANG.alpha_beta_gamma[1] -= 3 * RADIAN) && ft_clear_and_draw(fdf);
	if (fdf->flag.right == 1)
		(ANG.alpha_beta_gamma[1] += 3 * RADIAN) && ft_clear_and_draw(fdf);
	if (fdf->flag.up == 1)
		(fdf->scale_x_y_z_all[2] -= 1) && ft_clear_and_draw(fdf);
	if (fdf->flag.zoomin == 1)
		(fdf->scale_x_y_z_all[3] += 0.1) && ft_clear_and_draw(fdf);
	if (fdf->flag.zoomout == 1 && (fdf->scale_x_y_z_all[3] > 0.3))
		(fdf->scale_x_y_z_all[3] -= 0.1) && ft_clear_and_draw(fdf);
	if (fdf->flag.down == 1)
		(fdf->scale_x_y_z_all[2] += 1) && ft_clear_and_draw(fdf);
	return (0);
}

int		ft_key_events(t_basis *fdf)
{
	mlx_hook(fdf->window, 2, 1, ft_key_press, fdf);
	mlx_hook(fdf->window, 3, 2, ft_key_release, fdf);
	return (ft_check_flag(fdf));
}
